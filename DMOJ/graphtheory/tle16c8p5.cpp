// Kurbydoo
// November 11th 2024
// TLE '16 Contest 8 P5 - Prom Night
// https://dmoj.ca/problem/tle16c8p5
// Template flow problem
// CS nerd is the sink
// Edge between males and females
// ans = residual of cs nerd
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, tot, source_node, sink_node;
int ni, ei, ans;
int residual_capacity[210][210];
vector<int> adj[210];

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 9999});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next: adj[cur]) {
            if (parent[next] == -1 && residual_capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, residual_capacity[cur][next]);
                if (next == t) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(tot + 10);
    int new_flow;
    
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        // printf("found flow of %d\n", new_flow);
        while (cur != s) {
            int prev = parent[cur];
            // printf("%d -> %d\n", prev, cur);
            residual_capacity[prev][cur] -= new_flow;
            residual_capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    tot = n + m + 1;
    source_node = tot;
    sink_node = 1;
    cin >> ni;
    ans = ni;
    for (int i = 0; i < ni; i++) {
        cin >> ei;
        adj[sink_node].push_back(ei + n);
        adj[ei + n].push_back(sink_node);
        residual_capacity[ei + n][sink_node] = 1;
    }
    // printf("hi\n");
    for (int i = 2; i <= n; i++) {
        cin >> ni;
        adj[source_node].push_back(i);
        adj[i].push_back(source_node);
        residual_capacity[source_node][i] = 1;
        for (int j = 0; j < ni; j++) {
            cin >> ei;
            adj[i].push_back(ei + n);
            adj[ei + n].push_back(i);
            residual_capacity[i][ei + n] = 1;
        }
    }

    // printf("init done\n");
    printf("%d\n", ans - maxflow(source_node, sink_node));
}
