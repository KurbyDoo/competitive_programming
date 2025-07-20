// Kurbydoo
// September 25rd, 2023
// A Noisy Class
// https://dmoj.ca/problem/anoisyclass
#include <bits/stdc++.h>

using std::cin;
using std::greater;
using std::memset;
using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

typedef pair<int, int> pii;

int n, m;
bool visited[10010];
int inc[10010];
unordered_map<int, vector<int>> graph;
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool search(int n)
{
    // printf("at %d %d\n", n, inc[n]);
    if (inc[n] > 0) return false;
    visited[n] = true;
    for (int e : graph[n])
    {
        if (visited[e])
            return true;
        // printf("sub %d\n", e);
        inc[e]--;
        if (search(e))
            return true;
    }
    return false;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    // printf("ASdsad\n");
    cin >> n >> m;

    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        inc[b]++;
    }
    // printf("ASdsasadsd\n");

    for (int i = 1; i <= n; i++)
    {
        // printf("adding %d %d\n", inc[i], i);
        pq.push({inc[i], i});
    }

    int a, b;
    while (!pq.empty())
    {
        a = pq.top().first;
        b = pq.top().second;
        pq.pop();
        // printf("%d %d\n", a, b);

        search(b);
        // if (visited[b]); continue;
    }
    for (int i = 1; i <= n; i++)
    {
        if (inc[i] > 0)
        {
            printf("N\n");
            return 0;
        }
    }
    printf("Y\n");
    return 0;
}