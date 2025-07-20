#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll n, u, v;
unordered_map<ll, vector<ll>> graph;
ll par[400010];
ll depth[400010];
ll amount[400010];
ll dia, end1, end2;
void dfs(int node, int p, int d) {
    par[node] = p;
    if (d > dia) {
        end2 = node;
        dia = d;
    }
    for (int e: graph[node]) {
        if (e == p) continue;
        dfs(e, node, d + 1);
    }
}

void depth_dfs(int node, int p) {
    depth[node] = 0;
    amount[node] = 1;
    for (int e: graph[node]) {
        if (e == p) continue;
        depth_dfs(e, node);
        if (depth[e] + 1 > depth[node]) {
            depth[node] = depth[e] + 1;
            amount[node] = amount[e];
        } else if (depth[e] + 1 == depth[node]) {
            amount[node] += amount[e];
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 0);
    end1 = end2;
    dia = 0;
    dfs(end1, -1, 0);
    ll ctr = -1;
    ll other = 0;
    ll rad = dia;
    while (end2 != -1) {
        if (rad > max(dia - other, other)) {
            rad = max(dia - other, other);
            ctr = end2;
        }
        end2 = par[end2];
        other += 1;
    }

    depth_dfs(ctr, -1);
    // for (int i = 1; i <= n; i++) {
    //     printf("%d: %d %d\n", i, depth[i], amount[i]);
    // }
    ll m1 = 0, m2 = 0;
    ll c1 = 0, c2 = 0;
    for (int e: graph[ctr]) {
        if (depth[e] > m1) {
            m2 = m1;      
            m1 = depth[e];      
        } else if (depth[e] > m2) {
            m2 = depth[e];
        }
    }
    ll ans = 0;
    if (m1 == m2) {
        for (int e: graph[ctr]) {
            if (depth[e] != m1) continue;
            c1 += amount[e];
        }
    } else {
        for (int e: graph[ctr]) {
            if (depth[e] == m1) c1 += amount[e];
            if (depth[e] == m2) c2 += amount[e];
        }
    }

    if (m1 == m2) {
        for (int e: graph[ctr]) {
            if (depth[e] != m1) continue;
            ans += amount[e] * (c1 - amount[e]);
        }
        ans /= 2;
    } else {
       ans = c1 * c2;

    }
    // printf("%d %d %d %d\n", m1, m2, c1, c2);
    printf("%lld %lld\n", m1 + m2 + 3, ans);
    // printf("center is %d rad = %d\n", ctr, rad);

}

// 8
// 1 3
// 2 3
// 3 4
// 4 5
// 2 6
// 6 7
// 7 8

// 7
// 1 2
// 1 3
// 3 4
// 4 5
// 2 6
// 2 7

// 12
// 1 2
// 2 3
// 3 4
// 1 5
// 5 6
// 6 7
// 7 8
// 8 9
// 8 10
// 8 11
// 8 12
