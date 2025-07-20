// Kurbydoo
// APril 27th, 2023
// GlobeX Cup '18 J5 - Errands
// https://dmoj.ca/problem/globexcup18j5
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
using std::queue;

int n, m, Q, c;
int u, v;
unordered_map<int, vector<int>> graph;
queue<pair<int, int>> q;
int dist[100010];
bool vis[100010];


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> Q >> c;

    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dist[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    q.push({c, 0});
    vis[c] = true;
    dist[c] = 0;
    while (!q.empty()) {
        int curNode, curDist;
        curNode = q.front().first;
        curDist = q.front().second;
        q.pop();

        for (int n: graph[curNode]) {
            if (!vis[n]) {
                vis[n] = true;
                dist[n] = curDist + 1;
                q.push({n, curDist + 1});
            }
        }
        
    }

    for (int i = 0; i < Q; i++) {
        cin >> u >> v;
        if (dist[u] == -1 || dist[v] == -1) {
            printf("%s\n", "This is a scam!");
        } else {
            printf("%d\n", dist[u] + dist[v]);

        }
    }


    
    return 0;
}