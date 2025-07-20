#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, ai, bi, ci;
ll adj[20][20];
ll dfs(int node, int visited, int past) {
    // printf("at %d from %d vis: %d\n", node, past, visited);
    if (visited == ((1 << node) - 1)) return 0;
    ll best = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == -1 || visited & (1 << (i - 1))) continue;
        best = max(best, dfs(i, (1 << (i - 1)) | visited, node) + adj[node][i]);
    }
    // printf("best at %d is %d\n", node, best);
    return best;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            adj[r][c] = -1;
            adj[c][r] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi >> ci;
        adj[ai][bi] = ci;
        adj[bi][ai] = ci;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(dfs(i, 1 << (i - 1), -1), ans);
    }
    printf("%lld\n", ans);
}