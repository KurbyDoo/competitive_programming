#include <bits/stdc++.h>
using namespace std;
int n, q;

int pre_max[500010];
int suff_max[500010];
int pre_count[500010];
int suff_count[500010];
int ratings[500010];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ratings[i];
    }

    for (int i = 1; i <= n; i++) {
        if (ratings[i] > pre_max[i - 1]) {
            pre_max[i] = ratings[i];
            pre_count[i] = 1;
            
        } else if (ratings[i] == pre_max[i - 1]) {
            pre_max[i] = pre_max[i - 1];
            pre_count[i] = pre_count[i - 1] + 1;
        } else {
            pre_max[i] = pre_max[i - 1];
            pre_count[i] = pre_count[i - 1];
        }
    }
    for (int i = n; i > 0; i--) {
        if (ratings[i] > suff_max[i + 1]) {
            suff_max[i] = ratings[i];
            suff_count[i] = 1;
            
        } else if (ratings[i] == suff_max[i + 1]) {
            suff_max[i] = suff_max[i + 1];
            suff_count[i] = suff_count[i + 1] + 1;
        } else {
            suff_max[i] = suff_max[i + 1];
            suff_count[i] = suff_count[i + 1];
        }
    }

    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        // printf("%d %d | %d %d\n", suff_max[b + 1], suff_count[b + 1], pre_max[a - 1], pre_count[a - 1]);
        if (pre_max[a - 1] > suff_max[b + 1]) {
            printf("%d %d\n", pre_max[a - 1], pre_count[a - 1]);
        } else if (pre_max[a - 1] < suff_max[b + 1]) {
            printf("%d %d\n", suff_max[b + 1], suff_count[b + 1]);
        } else {
            printf("%d %d\n", suff_max[b + 1], suff_count[b + 1] + pre_count[a - 1]);
        }
    }
}
