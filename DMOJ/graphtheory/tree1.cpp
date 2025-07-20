#include <bits/stdc++.h>
using namespace std;
int edge_count = 0;
int adj[4][4];
bool visited[4];
bool dfs(int node, int past) {
    for (int e = 0; e < 4; e++) {
        if (!adj[node][e]) continue;
        if (e == node) return false;
        if (e == past) continue;
        if (visited[e]) return false;
        visited[e] = true;
        if (!dfs(e, node)) return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cin >> adj[x][y];
        }
    }
    visited[0] = true;
    if (dfs(0, -1)) {
        bool valid = true;
        for (int i = 0; i < 4; i++) {
            if (!visited[i]) valid = false;
        }
        printf("%s\n", valid ? "Yes" : "No");

    } else {
        printf("No\n");
    }
}