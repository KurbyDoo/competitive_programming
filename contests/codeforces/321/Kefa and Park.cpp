/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/580/C
 * Status: Solved
 * Notes:
 *     Original creation date unknown
 *     
 *     
 *     
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
int cats[100010], n, m, ui, vi;
int dfs(int node, int past, int tol) {
    if (tol == 0 && cats[node]) return 0;
    if (node != 1 && adj[node].size() == 1) return 1;
    int ans = 0;
    for (int e: adj[node]) {
        if (e == past) continue;
        ans += dfs(e, node, cats[node] ? tol - cats[node] : m);
    }
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    printf("%d\n", dfs(1, -1, m));
}