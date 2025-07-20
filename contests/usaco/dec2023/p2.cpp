#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a_loc[500010];
int b_loc[500010];
int b_loc_rev[500010];
int freq[500010];
int freq_rev[500010];
int n, k, a, b, ans = 0, best = 0;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a;
        a_loc[a] = i;
    }
    for (int i = 1; i <= k; i++) {
        cin >> b;
        b_loc[b] = i;
        b_loc_rev[b] = k - i + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a_loc[i] + b_loc[i] == 0) ans += 1;
        if (a_loc[i] == 0) continue;
        if (b_loc[i] == 0) continue;
        freq[(a_loc[i] - b_loc[i] + k) % k] += 1;
        freq_rev[(a_loc[i] - b_loc_rev[i] + k) % k] += 1;
    }

    for (int i = 0; i < k; i++) {
        best = max(best, max(freq[i], freq_rev[i]));
    }
    printf("%d\n", ans + best);
    return 0;
}
// 8 5
// 1 3 4 5 6
// 3 2 6 7 4