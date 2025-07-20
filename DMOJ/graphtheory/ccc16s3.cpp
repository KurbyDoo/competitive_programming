// Kurbydoo
// February 9th, 2023
// CCC '16 S3 - Phonomenal Reviews
// https://dmoj.ca/problem/ccc16s3
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;
using std::max;

unordered_map<int, vector<int>> graph;
int numberOfEdges[100010];
bool restaurants[100010];
bool trimmed[100010];
int lastRestaurant;
int n, m, r;
int v, u;
int nEdges = 0;

void trimLeaf(int node) {
    if (numberOfEdges[node] != 1) {
        return;
    }

    if (restaurants[node]) {
        return;
    }

    trimmed[node] = true;
    numberOfEdges[node] -= 1;
    nEdges -= 2;
    for (int e : graph[node])
    {
        if (!trimmed[e]) {
            numberOfEdges[e] -= 1;
            trimLeaf(e);
        }
    }

}


void trim() {
    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1) {
            trimLeaf(i);
        }
    }
}

pair<int, int> dfs(int node, int past, int dist) {
    // printf("at %d with dist of %d\n", node, dist);
    int maxDist = dist;
    int furthest = node;
    for (int e: graph[node]) {
        if (e == past || trimmed[e]) continue;
        
        pair<int, int> next = dfs(e, node, dist + 1);
        if (maxDist < next.first) {
            maxDist = next.first;
            furthest = next.second;
        }
    }

    return {maxDist, furthest};
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> r;
        restaurants[r] = true;
        lastRestaurant = r;
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> v >> u;
        nEdges += 2;
        numberOfEdges[v]++;
        numberOfEdges[u]++;
        graph[v].push_back(u);
        graph[u].push_back(v);
        
    }

    trim();
    pair<int, int> endNode;
    pair<int, int> furthest;
    endNode = dfs(lastRestaurant, -1, 0);
    furthest = dfs(endNode.second, -1, 0);

    // printf("maxdist = %d, edges = %d\n", furthest.first, nEdges);
    printf("%d\n", nEdges - furthest.first);

    // for (int i = 0; i < n; i++) {
    //     printf("Node %d: [", i);
    //     for (int e: graph[i]) {
    //         printf("%d,", e);
    //     }
    //     printf("]\n");
    // }

    
    return 0;
}

// 7 2
// 4 5
// 0 5
// 1 5
// 2 3
// 2 4
// 4 5
// 5 6