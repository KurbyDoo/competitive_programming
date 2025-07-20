#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
int u, v;
char w;
vector<pll> adj[100010];
int sz[100010];
int rem[100010];
ll ans = 0;

int gsz(int node, int past) {
    sz[node] = 1;
    for (auto [e, d]: adj[node]) {
        if (rem[e] || e == past) continue;
        sz[node] += gsz(e, node);
    }
    return sz[node];
}

int gctr(int node, int past, int tsz) {
    for (auto [e, d]: adj[node]) {
        if (rem[e] || e == past) continue;
        if (sz[e] * 2 > tsz) return gctr(e, node, tsz);
    }
    return node;
}

void gdst(int node, int past, int cur, vector<int> &dist) {
    dist.push_back(cur);
    for (auto [e, d]: adj[node]) {
        if (e == past || rem[e]) continue;
        gdst(e, node, cur + d, dist);
    }
}

void solve(int node) {
    int ctr = gctr(node, -1, gsz(node, -1));

    unordered_map<int, int> opp;
    opp.clear();
    opp[0] = 1;
    for (auto [e, d]: adj[ctr]) {
        if (rem[e]) continue;
        vector<int> dist;
        gdst(e, ctr, d, dist);
        // printf("%d to %d\n", ctr, e);
        for (int l: dist) {
            // printf("%d - adding %d for %d\n", ctr, opp[1 - l] + opp[-1 - l], l);
            ans += opp[1 - l] + opp[-1 - l];
        }
        for (int l: dist) {
            opp[l] += 1; // avoid matching within same st
        }
    }

    rem[ctr] = true;
    for (auto [e, d]: adj[ctr]) {
        if (rem[e]) continue;
        solve(e);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w == 'r' ? 1 : -1});
        adj[v].push_back({u, w == 'r' ? 1 : -1});
    }
    solve(1);
    printf("%lld\n", ans - n + 1);
    return 0;

}