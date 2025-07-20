#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m, a, b, c;
unordered_map<int, vector<pii>> graph;
priority_queue<pii> pq;
int score[200010];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    score[1] = 1e9 + 10;
    pq.push({score[1], 1});
    while (!pq.empty())
    {
        auto [cur_score, cur_node] = pq.top();
        pq.pop();
        for (auto [e, p]: graph[cur_node]) {
            if (min(score[cur_node], p) > score[e]) {
                score[e] = min(score[cur_node], p);
                pq.push({score[e], e});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", i == 1 ? 0 : score[i]);
    }
}