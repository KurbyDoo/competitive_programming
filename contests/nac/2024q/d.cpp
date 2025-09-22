#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
map<ll, vector<ll>> tree;
map<ll, ll> colours[100010];
map<ll, ll> all_colours;
vector<pii> edges;
ll node_colors[100010];
ll ans[100010];
ll depth[100010];
ll sz[100010];
ll parent[100010];
ll n, u, v;
void dfs(ll node, ll last, ll r) {
    sz[node] = 1;
    depth[node] = r;
    parent[node] = node;
    ll max_parent = node;
    for (ll e: tree[node]) {
        if (e == last) continue;
        dfs(e, node, r + 1);
        if (sz[e] >= sz[max_parent]) {
            max_parent = e;
        }
    }
    parent[node] = parent[max_parent];
    ans[node] = ans[max_parent];
    // printf("parent of %d is %d\n", node, parent[max_parent]);
    for (ll e: tree[node]) {
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
    for (ll i = 1; i <= n; i++) {
        cin >> node_colors[i];
        all_colours[node_colors[i]]++;
    }

    for (ll i = 1; i < n; i++) {
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
        printf("%lld\n", ans[lower]);
    }

    return 0;
}