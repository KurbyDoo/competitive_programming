#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, q, ai, bi, qi, s;
ll dist[3010];
bool visited[3010];
ll adj[3010][3010];
vector<pll> points;
vector<ll> sorted_dist;
ll get_dist(ll a, ll b) {
    return (points[a].first - points[b].first) * (points[a].first - points[b].first) + (points[a].second - points[b].second) * (points[a].second - points[b].second);
}
int solve(ll t) {
    if (t >= sorted_dist[n - 1]) return n;
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        // printf("mid = %d sd = %d\n", mid, sorted_dist[mid]);
        if (sorted_dist[mid] <= t) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l + 1;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai >> bi;
        points.push_back({ai, bi});
        dist[i] = 100000000000000LL;
    }
    cin >> s;
    dist[s - 1] = 0;
    int v = -1;
    for (int i = 0; i < n; i++) {
        v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        visited[v] = true;
        sorted_dist.push_back(dist[v]);
        for (int j = 0; j < n; j++) {
            if (visited[j]) continue;
            dist[j] = min(dist[j], dist[v] + get_dist(v, j));
        }
    }
    // for (int i = 0; i < n; i++) {
    //     printf("infect %d\n", sorted_dist[i]);

    // }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> qi;
        printf("%d\n", solve(qi));
    }
    return 0;
}