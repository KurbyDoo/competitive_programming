#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, ni;
int par[1000010];
int end1, end2, dia = 0;
int dfs(int node, int prev, unordered_map<int, vector<int>> &tree) {
    int big = 0;
    int edge_count = 0;
    for (int e: tree[node]) {
        if (e == prev) continue;
        edge_count += 1;
        big = max(dfs(e, node, tree) + 1, big);
    }
    int d = 0;
    edge_count -= 1;
    while (edge_count > 0) {
        d += 1;
        // printf("%d\n", edge_count);
        edge_count = edge_count >> 1;
    }
    big = max(big, d);
    // printf("at %d %d %d\n", node, big);
    return big;
}
void solve() {
    unordered_map<int, vector<int>> tree;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> ni;
        tree[ni].push_back(i);
        tree[i].push_back(ni);
    }

    printf("%d\n", dfs(1, -1, tree));
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}