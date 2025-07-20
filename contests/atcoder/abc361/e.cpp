#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
unordered_map<int, vector<pll>> graph;
ll pst[200010];
ll n, a, b, c, total_length;
ll dfs(int node, int past) {
    ll max_dist = 0;
    pst[node] = node;
    for (auto [e, d]: graph[node]) {
        if (e == past) continue;
        ll dist = dfs(e, node) + d;
        if (dist > max_dist) {
            pst[node] = pst[e];
            max_dist = dist;
        }
    }
    return max_dist;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        total_length += c;
    }
    dfs(1, -1);
    ll longest = dfs(pst[1], -1);
    // printf("%lld from %d\n", longest, pst[1]);
    printf("%lld\n", total_length * 2 - longest);
}