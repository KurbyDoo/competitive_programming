#include <bits/stdc++.h>
using namespace std;
int depth[500010];
int max_depth[500010];
int psa[500010];
void dfs(int node, int past, unordered_map<int, vector<int>> &graph) {
    depth[node] = depth[past] + 1;
    max_depth[node] = depth[node];
    for (int e: graph[node]) {
        if (e == past) continue;
        dfs(e, node, graph);
        max_depth[node] = max(max_depth[node], max_depth[e]);
    }
}
void solve() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> graph;
    psa[1] = 0;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        psa[i + 1] = 0;
    }
    depth[0] = 0;
    dfs(1, 0, graph);
    for (int i = 1; i <= n; i++) {
        psa[depth[i]] += 1;
        psa[max_depth[i] + 1] -= 1;
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        psa[i] += psa[i - 1];
        ans = min(ans, n - psa[i]);
        // printf("ans for %d = %d\n", i, n - psa[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}