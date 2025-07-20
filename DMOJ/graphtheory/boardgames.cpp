// Kurbydoo
// Feb 16th, 2023
// Board Games
// https://dmoj.ca/problem/boardgames
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cin;
using std::pair;
using std::queue;
using std::unordered_map;
using std::vector;

int n, m;
bool visited[10000010];
queue<pair<int, int>> q;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    q.push({n, 0});
    while (!q.empty())
    {
        int curNode = q.front().first;
        int curDist = q.front().second;
        q.pop();

        if (curNode == m)
        {
            printf("%d\n", curDist);
            break;
        }

        // printf("%d\n", curNode * 3);
        if (curNode * 3 < 10000010 && !visited[curNode * 3])
        {
            visited[curNode * 3] = true;
            q.push({curNode * 3, curDist + 1});
        }

        if (curNode > 0 && !visited[curNode - 1])
        {
            visited[curNode - 1] = true;
            q.push({curNode - 1, curDist + 1});
        }

        if (curNode > 2 && !visited[curNode - 3])
        {
            visited[curNode - 3] = true;
            q.push({curNode - 3, curDist + 1});
        }

        if (curNode % 2 == 0 && !visited[curNode / 2])
        {
            visited[curNode / 2] = true;
            q.push({curNode / 2, curDist + 1});
        }
    }

    return 0;
}