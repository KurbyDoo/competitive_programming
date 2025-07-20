#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10010];
bool visited[10010];
int n, c, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        for (int j = 0; j < c; j++) {
            cin >> a;
            adj[i].push_back(a);
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1] = true;
    int min_dist = 999999;
    while (!q.empty()) {
        // printf("at %d\n");
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (adj[cur].size() == 0) min_dist = min(min_dist, dist);
        for (int e: adj[cur]) {
            if (visited[e]) continue;
            q.push({e, dist + 1});
            visited[e] = true;
        }
    }
    bool valid = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) valid = false;
    }
    printf("%s\n", valid ? "Y" : "N");
    printf("%d\n", min_dist);
}