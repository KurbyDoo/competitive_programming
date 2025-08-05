/**
 * Author: KurbyDoo
 * Creation Date: Aug 04, 2025
 * Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=694
 * Problem Name: USACO 2017 January Contest, Gold 
 * Problem 2. Hoof, Paper, Scissors 
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

ll dp[100010][25][3];
ll moves[100010];
ll n, k;
char m;

int main() {
    std::ifstream infile("hps.in");

    infile >> n >> k;
    for (int i = 1; i <= n; i++) {
        infile >> m;
        if (m == 'P') {
            moves[i] = 0;
        } else if (m == 'H') {
            moves[i] = 1;
        } else {
            moves[i] = 2;
        }
    }

    for (int ki = 0; ki <= k; ki++) {
        for (int i = 1; i <= n; i++) {
            for (int mi = 0; mi < 3; mi++) {
                dp[i][ki][mi] = dp[i - 1][ki][mi] + (mi == moves[i]);
            }
            if (ki > 0)
                dp[i][ki][moves[i]] =
                    max(dp[i][ki][moves[i]],
                        max(dp[i][ki - 1][(moves[i] + 1) % 3],
                            dp[i][ki - 1][(moves[i] + 2) % 3]) +
                            1);
        }
    }

    ll ans = 0;
    for (int ki = 0; ki <= k; ki++) {
        for (int mi = 0; mi < 3; mi++) {
            ans = max(ans, dp[n][ki][mi]);
        }
    }

    ofstream out_file;
    out_file.open("hps.out");
    out_file << ans << '\n';
    out_file.close();
    return 0;
}