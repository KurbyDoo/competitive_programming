/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/431/C
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
const ll MOD = 1e9 + 7LL;
int n, d, k;
ll dp[2][110];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[1][i] = (dp[1][i] + dp[1][i - j]) % MOD;
            if (j >= d) dp[1][i] = (dp[1][i] + dp[0][i - j]) % MOD;
            else dp[0][i] = (dp[0][i] + dp[0][i - j]) % MOD; 
        }
    }
    printf("%lld\n", dp[1][n]);
}
