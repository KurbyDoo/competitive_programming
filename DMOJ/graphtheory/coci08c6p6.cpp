#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m, ci, ai[1200], bi[1200], total_cards = 0, max_node = 0, src_node, sink_node;
ll capacity[1200][1200];
vector<ll> adj[1200];
ll past[1200];

ll bfs() {
    memset(past, -1, sizeof(past));
    queue<pll> q;
    q.push({src_node, 999999999});
    past[src_node] = -2;
    while (!q.empty()) {
        auto [cur_node, cur_flow] = q.front();
        q.pop();
        for (auto next_node : adj[cur_node]) {
            if (past[next_node] == -1 && capacity[cur_node][next_node]) {
                ll next_flow = min(capacity[cur_node][next_node], cur_flow);
                past[next_node] = cur_node;
                if (next_node == sink_node) return next_flow;
                q.push({next_node, next_flow});
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    max_node = n + m + 1;
    src_node = 0;
    sink_node = max_node + 1;
    for (int i = 1; i <= n; i++) {
        cin >> ci;
        total_cards += ci;
        capacity[i][sink_node] = ci;
        adj[i].push_back(sink_node);
        adj[sink_node].push_back(i);
    }

    int others = total_cards / 2 - m;

    for (int i = n + 1; i <= n + m; i++) {
        cin >> ai[i] >> bi[i];
        capacity[src_node][i] = 2;
        capacity[i][ai[i]] = 2;
        capacity[i][bi[i]] = 2;
        adj[i].push_back(ai[i]);
        adj[i].push_back(bi[i]);
        adj[i].push_back(src_node);
        adj[ai[i]].push_back(i);
        adj[bi[i]].push_back(i);
        adj[src_node].push_back(i);
    }

    for (int i = n + m + 1; i <= n + total_cards / 2; i++) {
        capacity[src_node][i] = 2;
        adj[i].push_back(src_node);
        adj[src_node].push_back(i);
        for (int j = 1; j <= n; j++) {
            capacity[i][j] = 2;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    ll next_flow = 0, max_flow = 0;
    while (next_flow = bfs()) {
        max_flow += next_flow;
        ll cur_node = sink_node;
        while (past[cur_node] != -2) {
            // printf("%d <- ", cur_node);
            capacity[past[cur_node]][cur_node] -= next_flow;
            capacity[cur_node][past[cur_node]] += next_flow;
            cur_node = past[cur_node];
        }
        // printf("%d\n", cur_node);
    }

    // printf("max flow = %lld\n", max_flow);
    printf("%lld\n", total_cards / 2);

    for (int i = n + 1; i <= n + m; i++) {
        printf("%lld %lld %lld\n", ai[i], bi[i], capacity[ai[i]][i]);
    }
    for (int i = n + m + 1; i <= n + total_cards / 2; i++) {
        bool found = false;
        for (int j = 1; j <= n; j++) {
            if (capacity[j][i] == 2) {
                printf("%lld %lld %lld\n", j, (j % n) + 1, 2);
                break;
            } else if (capacity[j][i] == 1) {
                if (found) {
                    printf("%lld %lld\n", j, 1);
                    break;
                }
                printf("%lld ", j);
                found = true;
            }
        }
    }
    return 0;
}