#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cin;
using std::cout;
using std::greater;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<pair<int, int>, int> edge;

ll MAX_DIST = 260000000;

int n, m;
int a, b, d;

ll best = MAX_DIST, second = MAX_DIST;

vector<edge> edges;
unordered_map<int, vector<pl>> graph1;
unordered_map<int, vector<pl>> graph2;
priority_queue<pl, vector<pl>, greater<pl>> pq;

ll distTo[5010];
ll distFrom[5010];
bool visited[5010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        edges.push_back({{a, b}, d});
        graph1[a].push_back({b, d});
        graph1[b].push_back({a, d});
        graph2[a].push_back({b, d});
        graph2[b].push_back({a, d});
    }

    for (int i = 0; i <= n; i++)
    {
        distTo[i] = MAX_DIST;
        visited[i] = false;
    }

    distTo[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        visited[curNode] = true;

        for (pl e : graph1[curNode])
        {
            int nextNode = e.first;
            int nextDist = e.second;

            if (!visited[nextNode])
            {
                if (curDist + nextDist < distTo[nextNode])
                {
                    distTo[nextNode] = curDist + nextDist;
                    pq.push({distTo[nextNode], nextNode});
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        distFrom[i] = MAX_DIST;
        visited[i] = false;
    }

    distFrom[n] = 0;
    pq.push({0, n});

    while (!pq.empty())
    {
        ll curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        visited[curNode] = true;

        for (pl e : graph2[curNode])
        {
            int nextNode = e.first;
            int nextDist = e.second;

            if (!visited[nextNode])
            {
                if (curDist + nextDist < distFrom[nextNode])
                {
                    distFrom[nextNode] = curDist + nextDist;
                    pq.push({distFrom[nextNode], nextNode});
                }
            }
        }
    }

    best = distTo[n];

    for (edge e : edges)
    {
        ll temp = distTo[e.first.first] + e.second + distFrom[e.first.second];
        if (temp > best && temp < second)
        {
            second = temp;
        }

        temp = distFrom[e.first.first] + e.second + distTo[e.first.second];
        if (temp > best && temp < second)
        {
            second = temp;
        }
    }

    printf("%llu\n", second);

    // printf("Best = %llu, second = %llu\n", best, second);
    return 0;
}