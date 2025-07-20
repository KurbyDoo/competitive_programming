#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int a, b, d;

unordered_map<int, vector<pii>> graph;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    for (int i = 1; i <= n; i++)
    {
        int curV = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (curV == -1 || dist[j] < dist[curV]))
                curV = j;
        }

        if (dist[curV] == INT32_MAX) break;

        visited[curV] = true;
        for (pii e: graph[curV]) {
            if (dist[curV] + e.second < dist[e.first])
            {
                dist[e.first] = dist[curV] + e.second;
            }

        }
    }
    return 0;
}