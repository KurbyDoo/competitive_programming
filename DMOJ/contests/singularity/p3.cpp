#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m, p;
unordered_map<int, vector<int>> graph;
set<int> to_check;
set<pll> valid_right;
set<pll, greater<pll>> valid_left;
ll loc[1000010];
ll dist[1000010];
ll parent_count[1000010];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> loc[i];
        dist[i] = -1;
    }
    dist[p] = 0;
    valid_left.insert({loc[p], p});
    valid_right.insert({loc[p], p});
    to_check.insert(p);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
        parent_count[a] += 1;
    }
    for (int i = 1; i <= n; i++) {
        if (parent_count[i] == 0) {
            to_check.insert(i);
        }
    }

    while (!to_check.empty()) {
        ll closest = -1;
        ll best = -1;
        for (int node: to_check) {
            auto lower = valid_left.lower_bound({loc[node], node});
            auto upper = valid_right.lower_bound({loc[node], node});
            pll l = *lower;
            pll r = *upper;
            if (lower == valid_left.end()) l = *upper;
            if (upper == valid_right.end()) r = *lower;
            if (closest == -1 || min(abs(l.first - loc[node]), abs(r.first - loc[node])) < closest)
            {
                closest = min(abs(l.first - loc[node]), abs(r.first - loc[node]));
                best = node;
            }
            // printf("l = %lld u = %lld for n = %d loc[n] = %d c = %d\n", l.first, r.first, node, loc[node], closest);
        }

        to_check.erase(best);
        dist[best] = closest;
        valid_left.insert({loc[best], best});
        valid_right.insert({loc[best], best});
        // printf("best = %d\n", best);
        // printf("dist = %lld\n", dist[best]);
        for (int e: graph[best]) {
            parent_count[e] -= 1;
            if (parent_count[e] == 0) {
                to_check.insert(e);
            }
        }
    }

    ll fuel = 0;
    for (int i = 1; i <= n; i++) {
        fuel = max(fuel, dist[i]);
    }
    printf("%lld\n", fuel);
    return 0;
}
// 6 0 1
// 3 9 10 4 1 2

// 7 3 4
// 1 2 3 4 5 6 7
// 2 5
// 5 3
// 7 1