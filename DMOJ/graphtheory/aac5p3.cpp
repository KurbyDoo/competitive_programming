// UNFINISHED

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>

using std::abs;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::min;
using std::pair;
using std::sort;
using std::unordered_map;
using std::vector;

const int M = 2e5 + 10;

unordered_map<int, vector<pair<int, int>>> graph;
int visited[M];
// vector<int> track[M];
int skiiers[M];
int size;

int searchSkiiers(int start, int end, int item)
{
    int l = start, r = end, mid;
    // printf("searching for %d\n", item);
    while (l < r)
    {
        mid = (l + r) / 2;
        // printf("searching %d - %d mid = %d\n", l, r, mid);
        if (skiiers[mid] <= item)
            l = mid + 1;
        else if (skiiers[mid] > item)
            r = mid;
    }
    // printf("%d is at index %d\n", item, l);
    return l;
}

int divide(int start, int end, int node)
{
    // printf("dividing at node: %d from %d - %d\n", node, start, end);
    vector<pair<int, int>> edges = graph[node];
    sort(edges.begin(), edges.end(), [](auto &left, auto &right) { return left.second > right.second; });

    // int l = start; r = end;
    int count = 0;
    if (!edges.size()) return 0;

    for (int i = 0; i < edges.size() - 1; i++)
    {
        int diff = (edges[i].second + edges[i + 1].second) / 2;
        int index = searchSkiiers(start, end, diff);
        visited[edges[i].first] = end - index;
        // for (int j = index; j < end; j++) track[edges[i].first].push_back(skiiers[j]);
        // printf("%d skiiers visited %d\n", end - index, edges[i].first);
        divide(index, end, edges[i].first);
        end = index;
    }

    visited[edges[edges.size() - 1].first] = end - start;
    // for (int i = start; i < end; i++) track[edges[edges.size() - 1].first].push_back(skiiers[i]);
    
    // printf("%d skiiers visited %d\n", end, edges[edges.size() - 1].first);
    divide(start, end, edges[edges.size() - 1].first);
    return 0;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> size;

    // int skiiers[k] = {0};
    int a, b, d;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
    }

    for (int i = 0; i < size; i++)
    {
        cin >> skiiers[i];
    }

    sort(skiiers, skiiers + size);

    visited[1] = size;
    divide(0, size, 1);

    for (int i = 1; i < n; i++)
    {
        // printf("node %d has %d visits\n", i, visited[i]);
        printf("%d ", visited[i]);
    }
    printf("%d\n", visited[n]);

    // for (int i = 1; i <= n; i++)
    // {
    //     printf("node %d visited by ", i);
    //     for (int a : track[i]) printf("%d ", a);
    //     printf("\n");
    // }
}
