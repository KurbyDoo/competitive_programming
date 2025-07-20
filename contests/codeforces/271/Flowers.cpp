/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/474/D
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
int t, k, ai, bi, dp[100010];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        if (i >= k) dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
        else dp[i] = 1;
    }
    for (int i = 1; i <= 100000; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    for (int i = 0; i < t; i++) {
        cin >> ai >> bi;
        if (dp[bi] < dp[ai - 1]) printf("%lld\n", (dp[bi] - dp[ai - 1] + MOD) % MOD);
        else printf("%lld\n", dp[bi] - dp[ai - 1]);
    }

}