#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using std::cin;
using std::greater;
using std::min;
using std::pair;
using std::priority_queue;
using std::swap;
using std::unordered_map;
using std::vector;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pair<int, int>> quad;

int n, m, u, v;
ll l, c;

ll minCost = 0;

int past[2010];
int rank[2010];
// ll dist[2010][2010];

priority_queue<quad, vector<quad>, greater<quad>> pq;
unordered_map<int, vector<pll>> graph;

ll search(int a, int b)
{
    // printf("searching %d\n", a);
    // bool visited[2005] = {false};
    ll dist[2005];
    for (int i = 0; i <= n; i++) {
        dist[i] = 100000000000000;
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq2;
    pq2.push({0, a});
    dist[a] = 0;
    while (!pq2.empty())
    {
        ll curDist = pq2.top().first;
        ll curNode = pq2.top().second;
        pq2.pop();

        // printf("updating %d\n", curNode);
        if (curNode == b) {
            return curDist;
        }
        for (pll e : graph[curNode])
        {
            ll nextNode = e.first;
            ll nextDist = e.second;
            // printf("checking %d %llu %llu\n", nextNode, nextDist, dist[nextNode]);
            if (dist[nextNode] > curDist + nextDist)
            {
                // printf("adding %d\n", nextNode);
                dist[nextNode] = curDist + nextDist;
                pq2.push({dist[nextNode], nextNode});
            }
        }
    }
    // return dist[a][b];
}

int find(int a)
{
    if (past[a] == a)
        return a;
    return past[a] = find(past[a]);
}

void join(int a, int b, ll cost, ll length)
{
    // printf("joining %d %d\n", a, b);
    a = find(a);
    b = find(b);

    if (rank[b] > rank[a])
    {
        swap(a, b);
    }

    past[b] = a;
    if (rank[a] == rank[b])
    {
        rank[a]++;
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        past[i] = i;
        rank[i] = 1;
        // for (int j = 0; j <= n; j++)
        // {
        //     dist[i][j] = 100000000000000;
        // }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> l >> c;
        pq.push({{l, c}, {u, v}});
    }

    ll len, cos, a, b;
    while (!pq.empty())
    {
        len = pq.top().first.first;
        cos = pq.top().first.second;
        a = pq.top().second.first;
        b = pq.top().second.second;
        pq.pop();
        if (find(a) != find(b))
        {
            // printf("joining %d %d for l =  %llu, c = %llu\n", a, b, len, cos);
            join(a, b, cos, len);
            minCost += cos;
            graph[a].push_back({b, len});
            graph[b].push_back({a, len});
        }
        else
        {
            // printf("checking %d %d for l =  %llu, c = %llu\n", a, b, len, cos);

            if (len < search(a, b))
            {
                // printf("smaller dist %llu %d %d\n", search(a, b), a, b);
                // printf("joining %d %d for l =  %llu, c = %llu\n", a, b, len, cos);

                join(a, b, cos, len);
                minCost += cos;
                graph[a].push_back({b, len});
                graph[b].push_back({a, len});
            }
        }
    }
    printf("%llu\n", minCost);
}

// 5 7
// 1 2 15 1
// 2 4 9 9
// 5 2 5 6
// 4 5 4 4
// 4 3 3 7
// 1 3 2 7
// 1 4 2 1

// 5 8
// 1 2 0 1
// 2 4 0 9
// 5 2 0 6
// 4 5 0 4
// 4 5 0 2
// 4 3 0 7
// 1 3 0 7
// 1 4 0 1

// 5 7
// 1 2 0 1
// 2 4 0 9
// 5 2 0 6
// 4 5 0 2
// 4 3 0 7
// 1 3 0 7
// 1 4 0 1

// 6 8
// 1 3 0 2
// 1 5 0 13
// 1 6 0 11
// 2 4 0 2
// 4 5 0 6
// 3 4 0 2
// 3 5 0 5
// 5 6 0 7

// 6 8
// 1 3 0 11
// 1 5 0 1232
// 1 6 0 1245701242
// 2 4 0 1289732132
// 4 5 0 2137127
// 3 4 0 1294127046
// 3 5 0 1237901223
// 5 6 0 1212341265