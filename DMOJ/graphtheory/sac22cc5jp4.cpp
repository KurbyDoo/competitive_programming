#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::unordered_map;
using std::vector;

unordered_map<int, vector<int>> graph;
bool visited[200005];

void search(int node)
{
    // printf("searching %d", node);
    visited[node] = true;
    for (int n: graph[node])
    {
        if (!visited[n])
        {
            search(n);
            printf("%d ", n);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, c, pre;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            cin >> pre;
            graph[i + 1].push_back(pre);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            search(i);
            printf("%d ", i);
        }
    }
}