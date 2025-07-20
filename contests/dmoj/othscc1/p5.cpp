// KurbyDoo
// Feb 17th, 2024
// OTHS Coding Competition 1 (Mock CCC) J5 - Scavenger Hunt
// https://dmoj.ca/problem/othscc1p5
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> state;
unordered_map<int, vector<pll>> graph;
ll n, m, k;
ll craft[35];
ll ki[35];
ll dist[20010][35];
bool building[20010][35];
ll min_time = 0, test_number = 0;
int visited[20010];
unordered_map<int, vector<int>> items;
priority_queue<state, vector<state>, greater<state>> pq;


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> craft[i + 1];
        min_time += craft[i + 1];
    }
    for (int i = 0; i < k; i++) {
        cin >> ki[i];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0, a; j < ki[i]; j++) {
            cin >> a;
            building[a][i + 1] = true;
            // printf("adding item %d at %d\n", i + 1, a);
            items[i + 1].push_back(a);
        }
    }
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dist[j][i] = 100000000000000000;
        }
    }

    pq.push({0, {0, 1}});
    while (!pq.empty()) {
        ll cur_time = pq.top().first;
        ll cur_k = pq.top().second.first;
        ll cur_node = pq.top().second.second;
        // printf("at %d %d %d\n", cur_time, cur_k, cur_node);
        pq.pop();
        if (building[cur_node][cur_k + 1] && cur_time < dist[cur_node][cur_k + 1]) {
            dist[cur_node][cur_k + 1] = cur_time;
            if (cur_k + 1 == k) min_time = min(min_time, cur_time);
            else pq.push({cur_time, {cur_k + 1, cur_node}});

        } else if (cur_time + craft[cur_k + 1] < dist[cur_node][cur_k + 1]) {
            dist[cur_node][cur_k + 1] = cur_time + craft[cur_k + 1];
            if (cur_k + 1 == k) min_time = min(min_time, dist[cur_node][cur_k + 1]);
            else pq.push({dist[cur_node][cur_k + 1], {cur_k + 1, cur_node}});
        }
        for (auto [e, d]: graph[cur_node]) {
            if (building[e][cur_k + 1] && cur_time + d < dist[e][cur_k + 1]) {
                dist[e][cur_k + 1] = cur_time + d;
                if (cur_k + 1 == k) {
                    min_time = min(min_time, dist[e][cur_k + 1]);
                    continue;
                }
                // printf("adding up %d %d %d\n", dist[e][cur_k + 1], cur_k + 1, e);
                pq.push({dist[e][cur_k + 1], {cur_k + 1, e}});
            }
            else if (cur_time + d < dist[e][cur_k]) {
                dist[e][cur_k] = cur_time + d;
                // printf("adding %d %d %d\n", dist[e][cur_k], cur_k, e);
                pq.push({dist[e][cur_k], {cur_k, e}});
            }
        }
    }
    printf("%lld\n", min_time);

    return 0;
}
// 10 2 30
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3
// 1 3 1
// 2 3 10