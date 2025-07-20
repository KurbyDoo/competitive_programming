#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::unordered_map;
using std::vector;

unordered_map<int, vector<pair<int, int>>> graph;
int prevNode[500005];
int prevDist[500005];
int endNode, diameter, startNode;

void search(int node, int dist, int past)
{
    // printf("searching node %d with a dist of %d\n", node, dist);

    if (dist > diameter)
    {
        diameter = dist;
        endNode = node;
    }

    for (auto n: graph[node])
    {
        if (n.first != past)
        {
            prevNode[n.first] = node;
            prevDist[n.first] = dist;
            search(n.first, dist + n.second, node);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    int u, v, w;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    search(1, 0, -1);
    startNode = endNode;
    search(endNode, 0, -1);
    // printf("furthest node is %d, with a distance of %d\n", start.first, start.second);


    // printf("Diameter is %d from %d to %d\n", end.second, start.first, end.first);
    printf("%d\n", diameter);

    int next, minMax;
    minMax = diameter;

    next = endNode;
    while (next != startNode)
    {
        // printf("left = %d right = %d\n", diameter - prevDist[next], prevDist[next]);
        minMax = min(max(diameter - prevDist[next], prevDist[next]), minMax);
        next = prevNode[next];
    }

    // printf("Radius is %d\n", minMax);
    printf("%d\n", minMax);

    return 0;
}
