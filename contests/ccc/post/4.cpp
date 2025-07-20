#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
unordered_map<int, unordered_map<int, int>> colouring;
unordered_map<int, vector<int>> graph;
vector<pii> edges;
bool visited[200010];
int n, m;
void dfs(int node, int past, int depth) {
    if (visited[node]) {
        // If we are visiting an edge that has already
        // been visited, then a cycle exists. This means
        // the edge between the current and previous node
        // can be coloured grey
        colouring[node][past] = 'G';
        return;
    }

    // If the node hasn't been visited before,
    // the previous edge must be red or blue
    // since no cycle can be formed.
    // Depending on the distance from the start of
    // the search, we assign the colour of the edge
    // (red for even depths, blue for odd depths)
    visited[node] = true;
    if (past != -1) colouring[past][node] = depth % 2 == 0 ? 'R' : 'B';
    
    // We repeat this process for all nodes
    // connected to the current node
    for (int e : graph[node]) {
        // Skip the node we came from since
        // we already processed the edge between
        // the current node and the previous node
        if (e == past) continue;
        dfs(e, node, depth + 1);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    // Take in number of nodes and number of edges
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        edges.push_back({a, b});

        // Use a map to store all edges
        // Stores the adjacent nodes to the current node
        // (there exist a path from v -> u_i)
        // graph[v] = {u_1, u_2, u_3, u_4}
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Run dfs on every unvisited node
    // If a node hasn't been visited before
    // it must be part of a new subgraph
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1, 0);
        }
    }

    // Loop through the input edges and print 
    // the assigned coloring 
    for (auto [a, b] : edges) {
        printf("%c", colouring[a][b] == 0 ? colouring[b][a] : colouring[a][b]);
    }
    printf("\n");
}