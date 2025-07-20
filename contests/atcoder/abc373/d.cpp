#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m;
ll ui, vi, wi;
unordered_map<int, vector<pll>> graph;
ll vals[200010];
int parents[200010];
bool visited[200010];
void dfs(int node) {
    for (auto [u, e]: graph[node]) {
        if (visited[u]) continue;
        vals[u] = vals[node] - e;
        visited[u] = true;
        dfs(u);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ui >> vi >> wi;
        graph[ui].push_back({vi, -wi});
        graph[vi].push_back({ui, wi});
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        vals[i] = 0;
        dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", vals[i]);
    }
}