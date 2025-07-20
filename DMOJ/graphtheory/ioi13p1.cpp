#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::unordered_map;
using std::vector;


unordered_map<int, vector<pair<int, int>>> graph;
bool visited[100005];
int prevNode[100005];
int prevDist[100005];
int maxDiameter, maxRadius1 = 0, maxRadius2 = 0, maxRadius3 = 0;
pair<int, int> dfs(int node, int curDist, int past)
{
    visited[node] = true;
    pair<int, int> cur = {node, curDist};
    for (auto n : graph[node])
    {
        if (n.first != past)
        {
            prevNode[n.first] = node;
            prevDist[n.first] = curDist;
            pair<int, int> returned = dfs(n.first, curDist + n.second, node);

            if (returned.second > cur.second) cur = returned;
        }
    }
    return cur;
}

int findRadius(int node)
{
    int startNode, endNode;
    pair<int, int> first = dfs(node, 0, -1);
    startNode = first.first;

    // printf("start node is %d for %d\n", startNode, node);
    pair<int, int> second = dfs(startNode, 0, -1);
    int curD = second.second;
    // printf("diameter = %d at %d\n", curD, node);
    endNode = second.first;
    if (second.second > maxDiameter) maxDiameter = second.second;

    int radius = second.second;
    int curN = endNode;
    while (curN != startNode)
    {
        radius = min(radius, max(prevDist[curN], curD - prevDist[curN]));
        curN = prevNode[curN];
    }
    return radius;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    for (int i = 0; i < M; i++)
    {
        graph[A[i]].push_back({B[i], T[i]});
        graph[B[i]].push_back({A[i], T[i]});
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            int r = findRadius(i);
            // printf("radius = %d at %d\n", r, i);
            if (r > maxRadius1) 
            {
                maxRadius2 = maxRadius1;
                maxRadius1 = r;
            }
            else if (r > maxRadius2)
            {
                maxRadius3 = maxRadius2;
                maxRadius2 = r;
            }
            else if (r > maxRadius3) maxRadius3 = r;
        }
    }
    // printf("maxDiameter = %d, maxR1 = %d, maxR2 = %d, maxR3 = %d\n", maxDiameter, maxRadius1, maxRadius2, maxRadius3);
    if (N == 1) return 0;
    if (maxDiameter == 0 && N > 2) return L * 2;
    if (M == N - 2) return max(maxDiameter, maxRadius1 + maxRadius2 + L);
    return max(max(maxDiameter, maxRadius1 + maxRadius2 + L), maxRadius2 + maxRadius3 + L * 2);
}

int main()
{
    // int n, m, l;
    // n = 12;
    // m = 8;
    // l = 2;   
    // int a[] = {0, 8, 2, 5, 5, 1, 1, 10};
    // int b[] = {8, 2, 7, 11, 1, 3, 9, 6};
    // int t[] = {4, 2, 4, 3, 7, 1, 5, 3};
    // printf("Travel time = %d\n", travelTime(n, m, l, a, b, t));
    // printf("------------------------------------------------------\n");
    // int n, m, l;
    // n = 12;
    // m = 4;
    // l = 2;
    // int a[] = {0, 4, 6, 10, 9, 2};
    // int b[] = {1, 5, 7, 11, 10, 3};
    // int t[] = {8, 9, 9, 10, 10, 2};
    // printf("Travel time = %d\n", travelTime(n, m, l, a, b, t));
    // printf("------------------------------------------------------\n");
    // int n, m, l;
    // n = 12;
    // m = 1;
    // l = 1;
    // int a[] = {4};
    // int b[] = {6};
    // int t[] = {4};
    // printf("Travel time = %d\n", travelTime(n, m, l, a, b, t));
    // printf("------------------------------------------------------\n");
    // int n, m, l;
    // n = 7;
    // m = 4;
    // l = 99;
    // int a[] = {1, 3, 2, 0};
    // int b[] = {2, 4, 5, 6};
    // int t[] = {2, 2, 2, 1};
    // printf("Travel time = %d\n", travelTime(n, m, l, a, b, t));
    // printf("------------------------------------------------------\n");
    int n, m, l;
    n = 12;
    m = 8;
    l = 99;
    int a[] = {0, 8, 2, 5, 5, 1, 1, 10};
    int b[] = {8, 2, 7, 11, 1, 3, 9, 6};
    int t[] = {4, 2, 4, 3, 7, 1, 5, 3};
    printf("Travel time = %d\n", travelTime(n, m, l, a, b, t));
    printf("------------------------------------------------------\n");
    return 0;
}