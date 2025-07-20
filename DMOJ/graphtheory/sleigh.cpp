#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;
using std::pair;
using std::max;

unordered_map<int, vector<pair<int, int>>> graph;
int maxDist = 0;

void dfs(int node, int dist, int past)
{
    maxDist = max(maxDist, dist);
    for (auto n: graph[node])
    {
        if (n.first != past)
        {
            dfs(n.first, dist + n.second, node);
        }
    }
}


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    int totalLength = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        totalLength += t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
    dfs(0, 0, -1);
    printf("%d\n", totalLength*2 - maxDist);
}