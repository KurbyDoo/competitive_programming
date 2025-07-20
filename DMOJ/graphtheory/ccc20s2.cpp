#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1000005];
// bool visited[1000005];  
int bfs(int end)
{
    queue<int> q;
    q.push(graph[1].front());
    // printf("Start is %d\n", graph[1].front());
    while (!q.empty())
    {
        int curNum = q.front();
        q.pop();
        // printf("Travelling to %d\n", curNum);

        if (curNum == end)
        {
            return 1;
        }

        for (int i = 0; i < graph[curNum].size(); i++)
        {
            if (graph[curNum][i] != 0)
            {
                q.push(graph[curNum][i]);
                graph[curNum][i] = 0;

            }
        }
    }
    return 0;

}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int y =   1; y <= m; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            int value;
            cin >> value;
            int n = x*y;
            graph[n].push_back(value);
            // graph[value].push_back(n);
        }
    }
    // for (auto x: graph)
    // {
    //     printf("%d -> [", x.first);
    //     for (auto y: x.second)
    //     {
    //         printf("%d, ", y);
    //     }
    //     printf("]\n");
    // }
    if (bfs(n*m) == 0)
    {
        printf("no");
    }
    else
    {
        printf("yes");
    }
    return 0;
}   