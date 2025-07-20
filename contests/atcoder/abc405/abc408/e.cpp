/**
 * Author: KurbyDoo
 * Creation Date: Jul 20, 2025
 * Problem Link: https://atcoder.jp/contests/abc408/tasks/abc408_e
 * Problem Name: E - Minimum OR Path 
 * Status: Solved
 * Notes:
 *  Iterate through each bit
 *  BFS to check connectivity
**/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, ui, vi, wi;
vector<pll> adj[200010];
ll visited[200010], cnt = 0;

ll bfs(ll pref, ll sz) {
    cnt += 1;
    queue<ll> queue;
    queue.emplace(1);
    while (!queue.empty()) {
        auto node = queue.front();
        // printf("at %lld\n", node);
        queue.pop();
        if (node == n) return true;
        for (auto [nnode, ndist] : adj[node]) {
            // printf("visited = %lld | %lld != %lld\n", visited[nnode], (ndist | pref) >> sz, pref >> sz);
            if (visited[nnode] == cnt || ((ndist | pref) >> sz) != (pref >> sz)) continue;
            queue.push(nnode);
            visited[nnode] = cnt;
        }
    }
    return false;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ui >> vi >> wi;
        adj[ui].emplace_back(vi, wi);
        adj[vi].emplace_back(ui, wi);
    }

    ll prefix = 0;
    for (ll i = 30; i >= 0; i--) {
        if (!bfs(prefix, i)) {
            prefix |= 1 << i;
        }
    }
    printf("%lld\n", prefix);
    
    return 0;
}