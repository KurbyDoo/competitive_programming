/**
 * Author: KurbyDoo
 * Creation Date: Aug 04, 2025
 * Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=863
 * Problem Name: USACO 2018 December Contest, Gold
 * Problem 3. Teamwork
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
ll dp[10010];
ll vals[10010];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    std::ifstream infile("teamwork.in");
    ofstream outfile;
    outfile.open("teamwork.out");

    infile >> n >> k;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        infile >> vals[i];
    }

    for (int i = 1; i <= n; i++) {
        ll cur_max = vals[i];
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) continue;
            cur_max = max(cur_max, vals[i - j + 1]);
            dp[i] = max(dp[i], dp[i - j] + cur_max * j);
        }
    }
    outfile << dp[n] << '\n';
    outfile.close();

    return 0;
}