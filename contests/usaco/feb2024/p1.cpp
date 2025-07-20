#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
unordered_map<int, vector<pll>> graph;
int n, m, c, r, k;
int attempt_number = 0;
vector<int> ans;
int visited[50010];
int dist[50010];

bool good_chargers(int start_node) {
    attempt_number += 1;
    int reachable = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start_node});
    visited[start_node] = attempt_number;
    dist[start_node] = 0;
    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (cur_node <= c) reachable += 1;
        if (reachable == k) {
            return true;
        }

        for (auto [e, d]: graph[cur_node]) {
            if ((visited[e] != attempt_number && cur_dist + d <= r) || cur_dist + d < dist[e]) {
                dist[e] = cur_dist + d;
                visited[e] = attempt_number;
                pq.push({cur_dist + d, e});
            }
        }
    }

    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> c >> r >> k;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = c + 1; i <= n; i++) {
        if (good_chargers(i)) {
            ans.push_back(i);
        }
    }

    printf("%d\n", ans.size());
    for (int e: ans) {
        printf("%d\n", e);
    }

    return 0;
}