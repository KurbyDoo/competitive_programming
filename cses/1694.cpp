#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
vector<pii> adj[510];
ll capacity[510][510];
ll par[510];
ll n, m, a, b, c, flow;
ll bfs(int s, int t) {
    for (int i = 0; i <= n; i++) {
        par[i] = -1;
    }

    par[s] = -2;
    queue<pii> q;
    q.push({s, 10000000000000000});
    while (!q.empty()) {
        int cur = q.front().first;
        ll flw = q.front().second;
        q.pop();
        for (auto [e, f]: adj[cur]) {
            if (par[e] == -1 && capacity[cur][e] > 0) {
                par[e] = cur;
                flw = min(flw, capacity[cur][e]);
                if (e == t) {
                    return flw;
                }
                q.push({e, flw});
            }
        }
    }
    return 0;
    
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        capacity[a][b] += c;
    }

    flow = 0;
    ll next_flow = 0;
    while (next_flow = bfs(1, n)) {
        flow += next_flow;
        int cur = n;
        while (cur != 1) {
            capacity[par[cur]][cur] -= next_flow;
            capacity[cur][par[cur]] += next_flow;
            cur = par[cur];
        }
    }
    printf("%lld\n", flow);
}