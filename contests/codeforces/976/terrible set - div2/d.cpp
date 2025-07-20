#include <bits/stdc++.h>
using namespace std;
int t;
int dsu[200010];
int sz[200010];
set<int> ans;


int find(int a) {
    if (dsu[a] == a) {
        return a;
    }
    return dsu[a] = find(dsu[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[b] > sz[a]) swap(a, b);
        dsu[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        sz[i] = 1;
    }

    int ai, di, ki;
    for (int i = 0; i < m; i++) {
        cin >> ai >> di >> ki;
        for (int d = 1; d <= ki; d++) {
            if (ai + d * di > n) break;
            join(ai, ai + d * di);
        }
    }
    ans.clear();
    for (int i = 1; i <= n; i++) {
        ans.insert(find(i));
    }
    printf("%d\n", ans.size());
    // for (int i: ans) {
    //     printf("%d ", i);
    // }
    // printf("\n");
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}