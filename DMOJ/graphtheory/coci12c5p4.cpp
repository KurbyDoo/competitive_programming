#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::cin;
using std::queue;
using std::pair;

unordered_map<int, vector<int>> graph;
bool visited[101005];
// int past[100005] = {0};

int main()
{
    int n, k, m;
    int edge;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> edge;
            graph[100001 + i].push_back(edge);
            graph[edge].push_back(100001 + i);
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    int node, dist;
    while (!q.empty())
    {
        node = q.front().first;
        dist = q.front().second;
        q.pop();

        if (node == n)
        {
            printf("%d\n", (dist/2) + 1);
            return 0;
        }

        for (int e: graph[node])
        {
            if (!visited[e])
            {
                q.push({e, dist + 1});
                visited[e] = true;
                // past[e] = node;
            }
        }
    }
    printf("-1\n");
    // int p = n;
    // while (p != 0)
    // {
    //     printf("%d - ", p);
    //     p = past[p];
    // }
    
    return 0;
}