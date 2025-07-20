#include <bits/stdc++.h>
using namespace std;
int dist[1610][3610];
unordered_map<int, vector<array<int, 3>>> graph;
int s, n, m, ai, bi, ci, di;
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> s;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi >> ci >> di;
        if (di) {
            graph[ai].push_back({bi, ci, ci});
            graph[bi].push_back({ai, ci, ci});
        } else {
            graph[ai].push_back({bi, ci, 0});
            graph[bi].push_back({ai, ci, 0});
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dist[i][j] = 2000000000;
        }
    }
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto [cur_d, cur_s, cur] = pq.top();
        pq.pop();
        for (auto [e, d1, d2]: graph[cur]) {
            if (cur_s + d2 <= s && dist[cur][cur_s] + d1 < dist[e][cur_s + d2]) {
                dist[e][cur_s + d2] = dist[cur][cur_s] + d1;
                pq.push({dist[e][cur_s + d2], cur_s + d2, e});
            }
        }
    }

    int ans = 2000000000;
    for (int i = 0; i <= s; i++) {
        ans = min(dist[n - 1][i], ans);
    }
    printf("%d\n", ans == 2000000000 ? -1 : ans);
}