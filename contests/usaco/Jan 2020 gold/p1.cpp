/**
 * Author: KurbyDoo
 * Creation Date: Aug 04, 2025
 * Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=993
 * Problem Name: USACO 2020 January Contest, Gold
 * Problem 1. Time is Mooney
 * Status: Solved
 * Notes:
 * Probs n^2, notice you can get at most 1k per day
 * However, cost per day is > 1000 when T > 1000
 * Hence, it is guarenteed that you make negative money
 * When T > 1000
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll> adj[1010];
queue<ll> q;
ll money[1010];
ll visited[1010];
ll dp[1010][1010];
ll n, m, c, ai, bi;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    std::ifstream infile("time.in");
    ofstream outfile;
    outfile.open("time.out");

    infile >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        infile >> money[i];
    }

    for (int i = 0; i < m; i++) {
        infile >> ai >> bi;
        adj[ai].push_back(bi);
    }

    fill(&dp[0][0], &dp[0][0] + (1010 * 1010), -999999999LL);

    dp[1][0] = 0;
    for (int ct = 0; ct <= 1000; ct++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][ct] == 999999999LL) continue;
            for (int edge : adj[i]) {
                dp[edge][ct + 1] =
                    max(dp[edge][ct + 1], dp[i][ct] + money[edge]);
            }
        }
    }
    for (int ct = 0; ct <= 20; ct++) {
        for (int i = 1; i <= n; i++) {
            cout << dp[i][ct] << " ";
        }
        cout << '\n';
    }

    ll ans = 0;
    for (ll ct = 0; ct <= 1000; ct++) {
        ans = max(ans, dp[1][ct] - c * ct * ct);
    }
    outfile << ans << '\n';
    outfile.close();

    return 0;
}