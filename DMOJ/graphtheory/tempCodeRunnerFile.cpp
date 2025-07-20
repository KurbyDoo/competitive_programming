#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::max;
using std::unordered_map;
using std::vector;

unordered_map<int, vector<int>> graph[5];
bool visited[5][105] = {0};
int length[5];

bool dfs(int graphN, int node, int dist)
{
    // printf("checking from %d to %d with dist = %d\n", past, node, dist);
    if (visited[graphN][node])
    {
        length[graphN] = dist - visited[graphN][node];
        return true;
    }
    visited[graphN][node] = dist;
    for (int n : graph[graphN][node])
    {
        // printf("calling to %d from %d\n", n, node);
        if (dfs(graphN, n, dist + 1))
            return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        int a, b;
        for (int j = 0; j < n; j++)
        {
            cin >> a >> b;
            graph[i][a].push_back(b);
            // graph[i][b].push_back(a);
        }

        dfs(i, 1, 0);
        printf("%d\n", length[i]);
    }
}