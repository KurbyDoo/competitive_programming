#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> graph;
int n, k, a, b, vk;
bool needed[200010];
int dfs(int node, int p) {
    int children = 1;
    bool important = needed[node];
    for (int e: graph[node]) {
        if (e == p) continue;
        int branch_size = dfs(e, node);
        if (branch_size > 0) {
            important = true;
            children += branch_size;
        }
    } 

    if (!important) return 0;
    return children; 
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < k; i++) {
        cin >> vk;
        needed[vk] = true;
    }

    printf("%d\n", dfs(vk, -1));
}