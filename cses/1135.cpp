/**
 * Author: KurbyDoo
 * Creation Date: Oct 11, 2025
 * Problem Link: link
 * Problem Name: name
 * Status: Unsolved
 * Notes:
 * 	LCA with binary lifting
 *
 *
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int MAX_VAL = 200005;
const int MAX_LOG = 18;
vector<ll> graph[200010];
ll depth[200010];
ll up[MAX_LOG + 1][200010];
ll n, q, a, b;

void dfs(int a, int prev) {
    up[0][a] = prev;
    for (int i = 1; i <= MAX_LOG; i++) {
        up[i][a] = up[i - 1][up[i - 1][a]];
    }
    depth[a] = depth[up[0][a]] + 1;
    for (int b : graph[a]) {
        if (b == up[0][a]) continue;
        dfs(b, a);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int i = MAX_LOG; i >= 0; i--) {
        if ((1 << i) <= k) {
            k -= (1 << i);
            a = up[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = MAX_LOG; i >= 0; i--) {
        while (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    depth[0] = -1;
    dfs(1, 0);

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        int ans = depth[a] + depth[b] - 2 * depth[lca(a, b)];
        printf("%d\n", ans);
    }
    return 0;
}