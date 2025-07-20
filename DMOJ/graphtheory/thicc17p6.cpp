#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int end1, end2, dia = 0;
int n, t, a, b, c, tot;
unordered_map<int, vector<pii>> graph;
int edges[200010];
int depth[200010];
int par[200010];
bool on_dia[200010];
void dfs(int node, int prev, int dist) {
    if (dist > dia) {
        dia = dist;
        end2 = node;
    }

    for (auto [e, d]: graph[node]) {
        if (e == prev) continue;
        par[e] = node;
        dfs(e, node, dist + d);
    }
}
void dfs2(int node, int prev, int ld, int rd) {
    depth[node] = max(ld, rd);
    for (auto [e, d]: graph[node]) {
        if (e == prev) continue;
        if (on_dia[e]) {
            dfs2(e, node, ld - d, rd + d);
        } else {
            dfs2(e, node, ld + d, rd + d);
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        edges[a]++;
        edges[b]++;
        tot += 2 * c;
    }
    dia = -1;
    dfs(1, -1, 0);
    end1 = end2;
    dia = -1;
    dfs(end1, -1, 0);
    int cur = end2;
    while (cur != end1) {
        on_dia[cur] = true;
        cur = par[cur];
    }
    on_dia[cur] = true;
    dfs2(end1, -1, dia, 0);
    for (int i = 1; i <= n; i++) {
        if (edges[i] != t) continue;
        printf("%d %d\n", i, tot - depth[i]);
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("d of %d = %d\n", i, depth[i]);
    // }
    return 0;
}
