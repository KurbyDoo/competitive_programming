// Kurbydoo
// March 20th, 2023
// Mock CCC '18 Contest 5 J5/S3 - Directed Graph Connectivity
// https://dmoj.ca/problem/nccc5j5s3
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;

int n, m, s, t;
unordered_map<int, vector<int>> graph;
vector<pair<int, int>> edges;
bool visited[55];

bool dfs(int node, pair<int, int> res) {
    visited[node] = true;

    if (node == n) return true;

    for (int e: graph[node]) {
        if (visited[e]) continue;
        if (node == res.first && e == res.second) continue;
        if (dfs(e, res)) return true;
    }
    return false;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)  {
        cin >> s >> t;
        graph[s].push_back(t);
        edges.push_back({s, t});
    }

    for (pair<int, int> e: edges) {
        for (int i = 0; i <= n; i++) {
            visited[i] = false;
        }
        printf("%s\n", dfs(1, e) ? "YES" : "NO");
        
    }

    return 0;
}