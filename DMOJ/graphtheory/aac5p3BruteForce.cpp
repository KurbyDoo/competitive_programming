#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using std::abs;
using std::cin;
using std::cout;
using std::min;
using std::pair;
using std::unordered_map;
using std::vector;

const int M = 2e5 + 10;

unordered_map<int, vector<pair<int, int>>> graph;
int visited[M];
vector<int> track[M];

void dfs(int node, int skill, int past)
{
    // printf("visiting %d\n", node);
    visited[node]++;
    track[node].push_back(skill);
    int minValue, minNode, minDiff;
    minValue = INT_MAX;
    for (auto y : graph[node])
    {
        if (y.first == past)
        {
            continue;
        }
        if (minValue > abs(skill - y.second))
        {
            minValue = abs(skill - y.second);
            minNode = y.first;
            minDiff = y.second;
        }
        else if (minValue == abs(skill - y.second))
        {
            if (y.second < minDiff)
            {
                minDiff = y.second;
                minNode = y.first;
            }
        }
    }

    if (minValue != INT_MAX)
    {
        dfs(minNode, skill, node);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    int a, b, d;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    for (int i = 0; i < k; i++)
    {
        int skill;
        cin >> skill;
        dfs(1, skill, -1);
    }

    for (int i = 1; i < n; i++)
    {
        printf("%d ", visited[i]);
    }
    printf("%d\n", visited[n]);

    for (int i = 1; i <= n; i++)
    {
        printf("node %d visited by ", i);
        for (int a: track[i]) printf("%d ", a);
        printf("\n");
    }
}
// 13 15
// 1 2 4
// 1 3 8
// 1 10 6
// 2 4 3
// 2 5 6
// 4 8 5
// 4 9 4
// 3 6 1
// 3 7 3
// 10 11 3
// 10 12 2
// 10 13 1
// 1 1 2 2 3 3 4 5 7 8 9 9 12 14 15

// 15 8 6 7 1 0 6 0 7 1 1 0 0
// node 1 visited by 1 1 2 2 3 3 4 5 7 8 9 9 12 14 15
// node 2 visited by 1 1 2 2 3 3 4 5
// node 3 visited by 8 9 9 12 14 15
// node 4 visited by 1 1 2 2 3 3 4
// node 5 visited by 5 
// node 6 visited by
// node 7 visited by 8 9 9 12 14 15
// node 8 visited by
// node 9 visited by 1 1 2 2 3 3 4
// node 10 visited by 7
// node 11 visited by 7
// node 12 visited by

// 15 7 7 7 0 0 7 0 7 1 1 0 0
// node 1 visited by 1 1 2 2 3 3 4 5 7 8 9 9 12 14 15
// node 2 visited by 1 1 2 2 3 3 4
// node 3 visited by 7 8 9 9 12 14 15
// node 4 visited by 1 1 2 2 3 3 4
// node 5 visited by
// node 6 visited by
// node 7 visited by 7 8 9 9 12 14 15
// node 8 visited by
// node 9 visited by 1 1 2 2 3 3 4
// node 10 visited by 5
// node 11 visited by 5
// node 12 visited by

// 3 5
// 1 2 2
// 1 3 4
// 1 2 3 4 5

// 5 3 2
// node 1 visited by 1 2 3 4 5
// node 2 visited by 1 2 3
// node 3 visited by 4 5

// 5 2 3
// node 1 visited by 1 2 3 4 5
// node 2 visited by 1 2
// node 3 visited by 3 4 5

// 5 3 2
// node 1 visited by
// node 2 visited by 1 2 3
// node 3 visited by 4 5