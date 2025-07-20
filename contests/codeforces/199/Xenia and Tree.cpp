#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[200010];
int sz[200010];
int min_d[200010];
vector<pii> parent[200010];
bool rem[200010];
const int INF = 1e9;

int get_sz(int node, int past) {
    sz[node] = 1;
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        sz[node] += get_sz(e, node);
    }
    return sz[node];
}

int get_centroid(int node, int tsz, int past) {
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        if (sz[e] * 2 > tsz) return get_centroid(e, tsz, node); 
    }
    return node;
}

void get_dist(int node, int centroid, int past, int cur_dist) {
    for (int e: adj[node]) {
        if (e == past || rem[e]) continue;
        get_dist(e, centroid, node, cur_dist + 1);
    }
    parent[node].push_back({centroid, cur_dist});
}

void build(int node) {
    int ctd = get_centroid(node, get_sz(node, -1), -1);

    for (int e: adj[ctd]) {
        if (rem[e]) continue;
        get_dist(e, ctd, ctd, 1);
    }

    rem[ctd] = true;
    for (int e: adj[ctd]) {
        if (rem[e]) continue;
        build(e);
    }
}

void paint(int node) {
    for (auto &[par, d]: parent[node]) {
        min_d[par] = min(min_d[par], d);
    }
    min_d[node] = 0;
}

int query(int node) {
    int ans = min_d[node];
    for (auto &[par, d]: parent[node]) {
        ans = min(ans, d + min_d[par]);
    }
    return ans;
}
int n, m, u, v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build(1);
    for (int i = 1; i <= n; i++) {
        min_d[i] = INF;
    }
    paint(1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (u == 1) {
            paint(v);
        } else {
            printf("%d\n", query(v));
        }
    }
    return 0;
}