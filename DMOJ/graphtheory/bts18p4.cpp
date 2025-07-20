#include <bits/stdc++.h>

using std::cin;
using std::unordered_map;
using std::vector;

typedef long long ll;
typedef long double ld;
int n;
bool good[100010];
bool visited[100010];
ll strength;
unordered_map<int, vector<int>> graph;

int firstNode, secondNode, firstDist, secondDist;
int maxDist, maxNode;

void dfs(int node, int dist, int past, int type)
{
    // printf("a\n");
    visited[node] = true;
    if (type == 1 && dist > firstDist)
    {
        firstDist = dist;
        firstNode = node;
    }

    if (type == 2 && dist > secondDist)
    {
        secondDist = dist;
        secondNode = node;
    }

    for (int edge : graph[node])
    {
        if (edge == past)
            continue;
        dfs(edge, dist + 1, node, type);
    }
}

int main()
{
    cin >> n;
    // printf("%lld\n", sqrtl(ld(10000000000000000)));
    for (int i = 1; i <= n; i++)
    {
        cin >> strength;
        ld dis = 1 + 4 * 1 * strength;
        if (ll(sqrtl(dis)) == sqrtl(dis) && ll(sqrtl(dis)) % 2 == 1)
        {
            good[i] = true;
        }
    }
    // printf("a");

    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        if (good[a] && good[b])
        {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    // printf("b");

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] || !good[i])
            continue;
        dfs(i, 1, -1, 1);
        dfs(firstNode, 1, -1, 2);
        if (secondDist >= maxDist)
        {
            maxNode = secondNode;
            maxDist = secondDist;
        }
    }

    printf("%d\n", maxDist);

    return 0;
}