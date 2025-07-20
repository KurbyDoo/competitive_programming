#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::pair;
using std::unordered_map;
using std::vector;

typedef long long ll;

unordered_map<int, vector<pair<int, int>>> graph;
ll prevNode[100005];
ll prevDist[100005];
bool visited[100005] = {false};
ll endNode, startNode, tempDiameter;

void search(int node, ll dist, int past)
{
    // printf("searching node %d with a dist of %d\n", node, dist);
    if (dist >= tempDiameter)
    {
        tempDiameter = dist;
        endNode = node;
    }

    for (auto n : graph[node])
    {
        if (n.first != past)
        {
            visited[n.first] = true;
            prevNode[n.first] = node;
            prevDist[n.first] = dist;
            search(n.first, dist + n.second, node);
        }
    }
}

ll findDiameter(int node)
{
    endNode = 0;
    startNode = 0;
    tempDiameter = 0;
    search(node, 0, -1);
    startNode = endNode;
    // printf("end found at %d\n", startNode);
    search(endNode, 0, -1);
    return tempDiameter;
}

ll findRadius(int node)
{
    tempDiameter = findDiameter(node);
    // printf("diameter at %d is %d\n", node, tempDiameter);
    ll next, minMax;
    minMax = tempDiameter;

    next = endNode;
    // printf("start node is %d end node is %d\n", startNode, endNode);
    while (next != startNode)
    {
        // printf("left = %d right = %d\n", tempDiameter - prevDist[next], prevDist[next]);
        minMax = min(max(tempDiameter - prevDist[next], prevDist[next]), minMax);
        next = prevNode[next];
    }

    // printf("Radius is %d\n", minMax);
    // printf("%d\n", minMax);
    return minMax;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    ll remaining = n - (m + 1);
    ll u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w; 

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }


    if (q == 1)
    {
        ll totalDiameter = 0, d;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                d = findDiameter(i);
                // printf("diameter at %d is %d\n", i, d);
                totalDiameter += d;
            }
        }
        // printf("Diameter is %d from %d to %d n = %d\n", diameter, startNode, endNode, n);
        // printf("%d\n", totalDiameter + remaining);
        cout << totalDiameter + remaining << "\n";
    }
    // printf("furthest node is %d, with a distance of %d\n", start.first, start.second);


    else if (q == 2)
    {
        ll maxRadius = 0, r;
        ll dupe = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                r = findRadius(i);
                // printf("radius at %d is %d\n", i, r);
                if (maxRadius < r)
                {
                    maxRadius = r;
                    dupe = 0;
                }
                else if (maxRadius == r) dupe = 1;
            }
        }

        // printf("Radius is %d\n", maxRadius);
        // printf("%d\n", maxRadius + dupe);
        cout << maxRadius + dupe << "\n";
        // int left = minMax, right = diameter - minMax;
        // if (left == right) printf("%d\n", max(left, right));
        // else printf("%d\n", max(left, right));
    }
    // 1188930417
    // printf("test = %d\n", test);
    // cout << test << "\n";

    return 0;
}
