#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;
using std::max;

const int MAX = 3e5+10;

int maxDist = 0;  
int m1 = -1, m2 = -1;
unordered_map<int, vector<int>> graph;
int visited[MAX] = {0};

void dfs(int node, int start)
{
    // printf("p{%d %d}\n", node, start);
    if (node < start)
    {
        if (node == m1)
        {
            m2 = max(start, m2);
            // printf("updated to %d %d\n", m1, m2);
        }
        else if (node > m1)
        {
            m1 = node;
            m2 = start;
        }
    }

    for (int e: graph[node])
    {
        if (!visited[e])
        {
            visited[e] = start;
            dfs(e, start);
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[b].push_back(a);
    }


    for (int i = n; i > 0; i--)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(i, i);
        }
    }
    
    if (m1 == -1)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n", m1, m2);
}