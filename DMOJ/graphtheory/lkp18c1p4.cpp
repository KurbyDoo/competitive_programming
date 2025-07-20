#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m, a, b, c, ai, bi, ci;
ll dist[100010];
unordered_map<int, vector<array<ll, 3>>> graph;

ll solve(ll val) {
    for (int i = 0; i <= n; i++) {
        dist[i] = 99999999999999LL;
    }
    dist[a] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[a], a});
    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        if (cur_dist > dist[cur]) continue;
        for (auto [e, d, lvl]: graph[cur]) {
            if (lvl > val) continue;
            if (dist[cur] + d < dist[e]) {
                dist[e] = dist[cur] + d;
                pq.push({dist[e], e});
            }
        }
    }
    // printf("%lld\n", dist[b]);
    return dist[b];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ai >> bi >> ci;
        graph[ai].push_back({bi, ci, i});
        graph[bi].push_back({ai, ci, i});
    }
    cin >> a >> b >> c;
    if (a == b) {
        printf("0\n");
        return 0;
    }
    ll l = 1, r = m + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll t = solve(mid);
        if (t < c) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", r == m + 1 ? -1 : r);
}