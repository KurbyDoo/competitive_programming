#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll capacity[20][20];
vector<int> adj[20];
ll source, sink, bloodin[10], bloodout[10];
ll par[20];
void add_edge(int u, int v, int d) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[v][u] = d;
}
int bfs(int s, int t) {
    for (int i = 0; i <= source; i++) {
        par[i] = -1;
    }
    queue<pll> q;
    q.push({s, 999999999});
    while (!q.empty()) {
        auto [cur, cur_flow] = q.front();
        // printf("at %lld with %lld\n", cur, cur_flow);
        q.pop();
        for (int e: adj[cur]) {
            if (par[e] == -1 && capacity[cur][e] > 0) {
                par[e] = cur;
                int new_flow = min(cur_flow, capacity[cur][e]);

                if (e == t) {
                    return new_flow;
                }
                q.push({e, new_flow});
            }
        }
    }
    return 0;
}
int main() {
    source = 17;
    sink = 0;
    for (int i = 1; i <= 8; i++) {
        cin >> bloodin[i];
        add_edge(i + 8, source, bloodin[i]);
    }
    for (int i = 1; i <= 8; i++) {
        cin >> bloodout[i];
        add_edge(sink, i, bloodout[i]);
    }
    // on
    add_edge(1, 9, 1000000000);
    // op
    add_edge(2, 9, 1000000000);
    add_edge(2, 10, 1000000000);
    // an
    add_edge(3, 9, 1000000000);
    add_edge(3, 11, 1000000000);
    // ap
    add_edge(4, 9, 1000000000);
    add_edge(4, 10, 1000000000);
    add_edge(4, 11, 1000000000);
    add_edge(4, 12, 1000000000);
    // bn
    add_edge(5, 9, 1000000000);
    add_edge(5, 13, 1000000000);
    // bp
    add_edge(6, 9, 1000000000);
    add_edge(6, 10, 1000000000);
    add_edge(6, 13, 1000000000);
    add_edge(6, 14, 1000000000);
    // abn
    add_edge(7, 9, 1000000000);
    add_edge(7, 11, 1000000000);
    add_edge(7, 13, 1000000000);
    add_edge(7, 15, 1000000000);
    // abp
    add_edge(8, 9, 1000000000);
    add_edge(8, 10, 1000000000);
    add_edge(8, 11, 1000000000);
    add_edge(8, 12, 1000000000);
    add_edge(8, 13, 1000000000);
    add_edge(8, 14, 1000000000);
    add_edge(8, 15, 1000000000);
    add_edge(8, 16, 1000000000);

    ll ans = 0;
    ll flow;
    while ((flow = bfs(source, sink))) {
        ans += flow;
        ll cur = sink;
        while (cur != source) {
            capacity[par[cur]][cur] -= flow;
            capacity[cur][par[cur]] += flow;
            cur = par[cur];
        }
    }
    printf("%lld\n", ans);
    return 0;
}