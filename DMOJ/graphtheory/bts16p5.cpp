#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll cherries[10010];
ll depth[10010];
unordered_map<int, vector<pii>> graph;
ll n, c, k;
ll ai, bi, ci;
int ans = 0;
void dfs(int node, int p) {
    for (auto [e, d]: graph[node]) {
        if (e == p) continue;
        dfs(e, node);
        if (depth[e] + d <= k && cherries[e] >= c) {
            // printf("cut at %d %d\n", node, e);
            ans++;
        }
        depth[node] += d + depth[e];
        cherries[node] += cherries[e];
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> c >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cherries[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> ai >> bi >> ci;
        graph[ai].push_back({bi, ci});
        graph[bi].push_back({ai, ci});
    }

    dfs(1, -1);
    printf("%d\n", ans);
    return 0;
}