/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/321/C
 * Status: Solved
 * Notes:
 *     Original creation date unknown
 *     
 *     
 *     
 */
#include <bits/stdc++.h>
using namespace std;
int sz[100010];
int n, u, v;
int rnk[100010];
bool rem[100010];
vector<int> adj[100010];

int get_sz(int node, int past) {
    sz[node] = 1;
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        sz[node] += get_sz(e, node);
    }
    return sz[node];
}

int get_ct(int node, int past, int tsz) {
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        if (sz[e] * 2 > tsz) return get_ct(e, node, tsz);
    }
    return node;
}

void build(int node, int cur_rnk) {
    int ctr = get_ct(node, -1, get_sz(node, -1));

    rnk[ctr] = cur_rnk;
    rem[ctr] = true;
    for (int e: adj[ctr]) {
        if (rem[e]) continue;
        build(e, cur_rnk + 1);
    }

}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build(1, 0);

    for (int i = 1; i < n; i++) {
        printf("%c ", 'A' + rnk[i]);
    }
    printf("%c\n", 'A' + rnk[n]);
}