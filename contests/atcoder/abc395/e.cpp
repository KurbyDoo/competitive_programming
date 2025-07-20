#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll N, M, X, a, b;
ll dist[400010];
unordered_map<int, vector<pii>> graph;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b + N].push_back({a + N, 1});
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = N * X + N * X;
        dist[i + N] = N * X + N * X;
        graph[i].push_back({i + N, X});
        graph[i + N].push_back({i, X});
    }

    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        ll cur_dist, cur_loc;
        tie(cur_dist, cur_loc) = pq.top();
        // printf("at %d\n", cur_loc);
        pq.pop();
        for (auto [u, c]: graph[cur_loc]) {
            if (dist[u] > dist[cur_loc] + c) {
                dist[u] = dist[cur_loc] + c;
                pq.push({dist[u], u});
            }
        }
    }

    printf("%lld\n", min(dist[N], dist[N + N]));
}
