#include <bits/stdc++.h>
using namespace std;
int tests, u, v, n = 0;
char tt;

int dfs(int node, int past, int mode, const vector<vector<int>>& adj, const vector<int>& t, vector<vector<int>>& dp) {
    if (dp[mode + 1][node] != -1) return dp[mode + 1][node];
    int tot = 0;
    for (int nn : adj[node]) {
        if (nn == past) continue;
        if (t[nn] == 0) {
            tot += min(
                dfs(nn, node, -1, adj, t, dp) + (mode == 1), 
                dfs(nn, node, 1, adj, t, dp) + (mode == -1)
            );
        } else if (t[nn] == mode) {
            tot += dfs(nn, node, mode, adj, t, dp);
        } else {
            tot += dfs(nn, node, mode * -1, adj, t, dp) + 1;
        }
    }
    return dp[mode + 1][node] = tot;
}

int solve() {
    cin >> n;
    vector<vector<int>> adj(n + 10);
    vector<int> t(n + 10);
    vector<vector<int>> dp(3, vector<int>(n + 10, -1));

    for (int i = 2; i <= n; i++) {
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> tt;
        if (tt == 'C') {
            t[i] = 0;
        } else if (tt == 'S') {
            t[i] = -1;
        } else {
            t[i] = 1;
        }
    }

    if (t[1] == 0) {
        return min(dfs(1, -1, 1, adj, t, dp), dfs(1, -1, -1, adj, t, dp));
    }
    return dfs(1, -1, t[1], adj, t, dp);
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> tests;
    while (tests--) {
        printf("%d\n", solve());
    }
    return 0;
}