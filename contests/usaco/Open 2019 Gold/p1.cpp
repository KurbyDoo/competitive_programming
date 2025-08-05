/**
 * Author: KurbyDoo
 * Creation Date: Aug 04, 2025
 * Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=945
 * Problem Name: USACO 2019 US Open Contest, Gold
 * Problem 1. Snakes
 * Status: Solved
 * Notes:
 *
 *
 *
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll n, k;
ll values[410];
ll dp2[2][410];
ll dp[410][410];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    std::ifstream infile("snakes.in");
    ofstream outfile;
    outfile.open("snakes.out");

    infile >> n >> k;
    for (int i = 1; i <= n; i++) {
        infile >> values[i];
    }

    fill(&dp[0][0], &dp[0][0] + (410 * 410), 999999999LL);
    fill(&dp2[0][0], &dp2[0][0] + 2 * 410, 999999999LL);

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int ki = 0; ki <= k; ki++) {
        for (int i = 0; i <= n; i++) {
            dp2[ki % 2][i] = 999999999LL;
        }
        for (int s = 1; s <= n; s++) {
            for (int i = 1; i <= n; i++) {
                if (values[s] < values[i]) continue;
                dp[s][i] = dp[s][i - 1] + (values[s] - values[i]);
                if (ki > 0)
                    dp[s][i] = min(dp[s][i], dp2[(ki + 1) % 2][i - 1] +
                                                 (values[s] - values[i]));
                dp2[ki % 2][i] = min(dp2[ki % 2][i], dp[s][i]);
            }
        }
    }

    ll ans = 999999999LL;
    for (int s = 1; s <= n; s++) {
        ans = min(ans, dp[s][n]);
    }
    outfile << ans << '\n';
    outfile.close();

    return 0;
}