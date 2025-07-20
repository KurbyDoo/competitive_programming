#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
unordered_map<int, vector<int>> graph;
int parents[100010];
int dp[100010];
deque<int> q;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        parents[b] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (parents[i] == 0)
        {
            q.push_back(i);
        }
    }
    while (!q.empty())
    {
        int id = q.front();
        // printf("at %d dist = %d\n", id, dp[id]);
        q.pop_front();
        for (int e : graph[id])
        {
            dp[e] = max(dp[e], dp[id] + 1);
            parents[e] -= 1;
            if (parents[e] == 0)
            {
                q.push_back(e);
            }
        }
    }
    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        best = max(dp[i], best);
    }
    printf("%d\n", best);
}