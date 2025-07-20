#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<int, vector<int>> tree;
map<int, int> colours[100010];
map<int, int> all_colours;
vector<pii> edges;
int node_colors[100010];
int ans[100010];
int depth[100010];
int sz[100010];
int parent[100010];
int n, u, v;
void dfs(int node, int last, int r) {
    sz[node] = 1;
    depth[node] = r;
    parent[node] = node;
    int max_parent = node;
    for (int e: tree[node]) {
        if (e == last) continue;
        dfs(e, node, r + 1);
        if (sz[e] >= sz[max_parent]) {
            max_parent = e;
        }
    }
    parent[node] = parent[max_parent];
    ans[node] = ans[max_parent];
    // printf("parent of %d is %d\n", node, parent[max_parent]);
    for (int e: tree[node]) {
        if (e == last) continue;
        sz[node] += sz[e];
        // printf("n: %d | %d : %d\n", node, e, max_parent);
        if (e == max_parent) continue;
        for (auto [key, val]: colours[parent[e]]) {
            // printf("-(%d)(%d - %d) = %d\n", colours[parent[node]][key], (all_colours[key]), (colours[parent[node]][key]), colours[parent[node]][key] * (all_colours[key] - colours[parent[node]][key]));
            ans[node] -= colours[parent[node]][key] * (all_colours[key] - colours[parent[node]][key]);
            colours[parent[node]][key] += val;
            ans[node] += colours[parent[node]][key] * (all_colours[key] - colours[parent[node]][key]);
            // printf("+(%d)(%d - %d) = %d\n", colours[parent[node]][key], (all_colours[key]), (colours[parent[node]][key]), colours[parent[node]][key] * (all_colours[key] - colours[parent[node]][key]));
        }
    }

    // printf("2-(%d)(%d - %d)\n", colours[parent[node]][node_colors[node]], (all_colours[node_colors[node]]), colours[parent[node]][node_colors[node]]);
    ans[node] -= colours[parent[node]][node_colors[node]] * (all_colours[node_colors[node]] - colours[parent[node]][node_colors[node]]);
    colours[parent[node]][node_colors[node]]++;
    ans[node] += colours[parent[node]][node_colors[node]] * (all_colours[node_colors[node]] - colours[parent[node]][node_colors[node]]);
    // printf("2+(%d)(%d - %d)\n", colours[parent[node]][node_colors[node]], (all_colours[node_colors[node]]), colours[parent[node]][node_colors[node]]);

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node_colors[i];
        all_colours[node_colors[i]]++;
    }

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edges.push_back({u, v});
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1, 0);
    // for (int i = 1; i <= n; i++) {
    //     printf("ans for %d = %d\n", i, ans[i]);
    // }
    for (auto [lower, upper]: edges) {
        if (depth[lower] < depth[upper]) swap(lower, upper);
        printf("%d\n", ans[lower]);
    }

    return 0;
}