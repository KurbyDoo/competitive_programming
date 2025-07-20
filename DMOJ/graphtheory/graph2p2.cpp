#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> graph;
int n, cur;
int visited[1005];

bool dfs(int node)
{
    // printf("visiting %d\n", node);
    if (visited[node] == 1) {
        // printf("%d is visited\n", node);
        return true;
    }
    visited[node] = 1;
    for (int e: graph[node])
    {
        // printf("checking %d\n", e);
        if (visited[e] != 2) if (dfs(e)) return true;
    }
    visited[node] = 2;
    return false;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cin >> cur;
            if (cur) graph[a].push_back(b);
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
        {
            // printf("searching from %d\n", i);
            if (dfs(i))
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}