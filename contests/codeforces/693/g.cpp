/**
 * Author: KurbyDoo
 * Creation Date: Aug 04, 2025
 * Problem Link: https://codeforces.com/contest/1472/problem/G
 * Problem Name: G. Moving to the Capital
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
ll t;

ll dfs(ll node, ll jumps, vector<ll>& dist, vector<vector<ll>>& adj,
       vector<vector<ll>>& dp) {
    // printf("at %lld %lld\n", node, jumps);
    if (dp[jumps][node] != -1) return dp[jumps][node];
    ll min_dist = dist[node];
    for (ll edge : adj[node]) {
        // printf("dist[%lld] >= dist[%lld] (%lld >= %lld)\n", edge, node,
        //        dist[edge], dist[node]);
        if (dist[edge] <= dist[node]) {
            if (!jumps) continue;
            min_dist = min(min_dist, dfs(edge, 0, dist, adj, dp));
        } else {
            min_dist = min(min_dist, dfs(edge, jumps, dist, adj, dp));
        }
    }
    // printf("ans for %lld %lld is %lld\n", jumps, node, min_dist);
    return dp[jumps][node] = min_dist;
}

void solve() {
    ll n, m, ai, bi;
    cin >> n >> m;
    // printf("n m = %lld %lld\n", n, m);
    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> dp(2, vector<ll>(n + 1, -1));
    vector<ll> dist(n + 1, -1);
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi;
        adj[ai].push_back(bi);
    }

    dist[1] = 0;
    queue<pll> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto [cn, cd] = q.front();
        q.pop();

        for (ll edge : adj[cn]) {
            if (dist[edge] != -1) continue;
            dist[edge] = cd + 1;
            q.push({edge, dist[edge]});
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%lld%s", dist[i], i == n ? "\n" : " ");
    // }
    dp[1][1] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        printf("%lld%s", dfs(i, 1, dist, adj, dp), i == n ? "\n" : " ");
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