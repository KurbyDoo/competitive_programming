#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pll> adj[200010];
ll dist[200010];
ll weights[200010];
bool visited[200010];
int n, m;
ll a, b, c;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
        dist[i] = 4000000000000000;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        ll cur_dist = pq.top().first;
        ll cur_node = pq.top().second;
        pq.pop();

        if (visited[cur_node]) continue;
        visited[cur_node] = true;

        for (auto [v, e]: adj[cur_node]) {
            if (dist[cur_node] + e + weights[cur_node] < dist[v]) {
                dist[v] = dist[cur_node] + e + weights[cur_node];
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dist[i] + weights[i]);
    }

        return 0;
}