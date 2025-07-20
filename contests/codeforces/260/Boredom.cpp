/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/455/A
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
ll nums[100010];
ll dp[100010];
int n, ai;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        nums[ai]++;
    }

    dp[1] = nums[1];
    for (ll i = 2; i <= 100000; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i] * i);
    }
    printf("%lld\n", dp[100000]);
}