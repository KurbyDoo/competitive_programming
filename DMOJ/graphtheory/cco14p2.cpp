// Author: KurbyDoo
// Created: 2025-07-02 18:41:50
// CCO '14 P2 - King Gruff
// https://dmoj.ca/problem/cco14p2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll, 4> edge;
typedef pair<ll, ll> pll;
ll n, m, a, b, q, di;
ll xi, yi, li, ci;
ll ans[100010];
vector<pll> adj[100010], radj[100010], edge_dists, dists;
vector<ll> dist_a, dist_b;
vector<edge> all_edges;
const ll MAX = 999999999999;

void do_dijkstra(ll sn, vector<ll>& dist, bool reverse) {
    dist[sn] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[sn], sn});
    while (!pq.empty()) {
        auto [cd, cn] = pq.top();
        pq.pop();
        if (reverse) {
            for (auto [nn, nd] : radj[cn]) {
                if (dist[cn] + nd < dist[nn]) {
                    dist[nn] = dist[cn] + nd;
                    pq.push({dist[nn], nn});
                }
            }
        } else {
            for (auto [nn, nd] : adj[cn]) {
                if (dist[cn] + nd < dist[nn]) {
                    dist[nn] = dist[cn] + nd;
                    pq.push({dist[nn], nn});
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        cin >> xi >> yi >> li >> ci;
        adj[xi].push_back({yi, li});
        radj[yi].push_back({xi, li});
        all_edges.push_back({xi, yi, li, ci});
    };

    dist_a = vector<ll>(n + 10, MAX);
    dist_b = vector<ll>(n + 10, MAX);

    cin >> q;
    dists = vector<pll>();
    for (int i = 0; i < q; i++) {
        cin >> di;
        dists.push_back({di, i});
    };
    sort(dists.begin(), dists.end());
    do_dijkstra(a, dist_a, false);
    do_dijkstra(b, dist_b, true);

    for (auto [x, y, d, c] : all_edges) {
        edge_dists.push_back({dist_a[x] + dist_b[y] + d, c});
    }
    sort(edge_dists.begin(), edge_dists.end(), greater<pll>());

    ll cur_cost = 0;
    for (auto [d, i] : dists) {
        while (!edge_dists.empty() && edge_dists.back().first <= d) {
            cur_cost += edge_dists.back().second;
            edge_dists.pop_back();
        }
        ans[i] = cur_cost;
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    };
    return 0;
}