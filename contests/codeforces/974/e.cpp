#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll t;
ll n, m, h, hi, ui, vi, wi;
ll dist1[400010], dist2[400010];
ll visited1[400010], visited2[400010];
vector<pll> graph[400010];
const ll MAX = 999999999999999LL;
void solve() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    cin >> n >> m >> h;
    for (int i = 1; i <= 2 * n; i++) {
        dist1[i] = MAX;
        dist2[i] = MAX;
        visited1[i] = false;
        visited2[i] = false;
        graph[i].clear();
    }
    for (int i = 0; i < h; i++) {
        cin >> hi;
        graph[hi].push_back({hi + n, 0});
    }
    for (int i = 0; i < m; i++) {
        cin >> ui >> vi >> wi;
        graph[ui].push_back({vi, wi});
        graph[vi].push_back({ui, wi});
        graph[ui + n].push_back({vi + n, wi / 2});
        graph[vi + n].push_back({ui + n, wi / 2});
    }

    dist1[1] = 0;
    visited1[1] = 0;
    pq.push({dist1[1], 1});
    while (!pq.empty()) {
        ll cn, cd;
        tie(cd, cn) = pq.top();
        pq.pop();
        if (visited1[cn]) continue;
        visited1[cn] = true;
        for (auto [e, d]: graph[cn]) {
            if (dist1[e] > dist1[cn] + d) {
                dist1[e] = dist1[cn] + d;
                pq.push({dist1[e], e});
            }
        }
    }

    dist2[n] = 0;
    visited2[n] = 0;
    pq.push({dist2[n], n});
    while (!pq.empty()) {
        ll cn, cd;
        tie(cd, cn) = pq.top();
        pq.pop();
        if (visited2[cn]) continue;
        visited2[cn] = true;
        for (auto [e, d]: graph[cn]) {
            if (dist2[e] > dist2[cn] + d) {
                dist2[e] = dist2[cn] + d;
                pq.push({dist2[e], e});
            }
        }
    }

    ll ans = MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(min(dist1[i], dist1[i + n]), min(dist2[i], dist2[i + n])));
    }
    if (ans == MAX) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }
    
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}