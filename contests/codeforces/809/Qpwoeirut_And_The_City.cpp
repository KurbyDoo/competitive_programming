/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/1706/C
 * Status: Solved
 * Notes:
 *     Original creation date unknown
 *     
 *     
 *     
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll heights[100010];
ll dp[2][100010];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    dp[0][0] = 0;
    dp[0][1] = 9999999999999999;
    dp[1][1] = 9999999999999999;
    dp[1][2] = 9999999999999999;
    if (n % 2 == 0) {
        for (int i = 2; i < n; i++) {
            ll diff = max(0LL, max(heights[i - 1], heights[i + 1]) + 1LL - heights[i]);
            dp[0][i] = dp[0][i - 2] + diff;
            if (i < 3) continue; 
            dp[1][i] = min(dp[1][i - 2] + diff, dp[0][i - 3] + diff);
        }
        printf("%lld\n", min(dp[0][n - 2], dp[1][n - 1]));
    } else {
        ll ans = 0;
        for (int i = 2; i < n; i += 2) {
            ans += max(0LL, max(heights[i - 1], heights[i + 1]) + 1LL - heights[i]);
        }
        printf("%lld\n", ans);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}