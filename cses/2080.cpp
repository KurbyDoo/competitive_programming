// Template Centroid Decomposition
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sz[200010];
bool rem[200010];
vector<int> adj[200010];
ll ans = 0;
ll n, u, v, k;
ll dists[200010];
ll max_depth = 0;
 
int gsz(int node, int past) {
    sz[node] = 1;
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        sz[node] += gsz(e, node);
    }
    return sz[node];
}
 
int gctr(int node, int past, int tsz) {
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        if (sz[e] * 2 > tsz) return gctr(e, node, tsz);
    }
    return node;
}
 
void gdst(int node, int past, ll cur, bool fill) {
    if (cur > k) return;
    max_depth = max(max_depth, cur);
    if (fill) dists[cur] += 1;
    else ans += dists[k - cur];
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        gdst(e, node, cur + 1, fill);
    }
}
 
void solve(int node) {
    int ctr = gctr(node, -1, gsz(node, -1));
    if (sz[node] < k) return;
    dists[0] = 1;
    for (int e: adj[ctr]) {
        if (rem[e]) continue;
        gdst(e, ctr, 1, false);
        gdst(e, ctr, 1, true);
    }
 
    fill(dists + 1, dists + max_depth, 0);
    rem[ctr] = true;
    for (int e: adj[ctr]) {
        if (rem[e]) continue;
        solve(e);
    }
}
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    printf("%lld\n", ans);
    return 0;
}