// Kurbydoo
// Feb 25th, 2023
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::min;
using std::pair;
using std::unordered_map;
using std::vector;

int n, m, c;
int grid[55][55];
int dp[55][55][55][55];

int getCost(int x1, int y1, int x2, int y2)
{
    if (dp[x1][y1][x2][y2])
    {
        // printf("calc");
        return dp[x1][y1][x2][y2];
    }

    if (x2 - x1 == 1 && y2 - y1 == 1)
    {
        // printf("%d %d %d %d\n", x1, y1, x2, y2);

        dp[x1][y1][x2][y2] = 0;
        return dp[x1][y1][x2][y2];
    }

    int minCost = INT32_MAX;
    for (int x = x1 + 1; x < x2; x++)
    {
        int cost = 0;
        cost += (grid[x1][y1] + grid[x][y2] - grid[x1][y2] - grid[x][y1]);
        cost += (grid[x][y1] + grid[x2][y2] - grid[x][y2] - grid[x2][y1]);
        cost += getCost(x1, y1, x, y2) + getCost(x, y1, x2, y2);
        minCost = min(cost, minCost);
    }

    for (int y = y1 + 1; y < y2; y++)
    {
        int cost = 0;
        cost += (grid[x1][y1] + grid[x2][y] - grid[x1][y] - grid[x2][y1]);
        cost += (grid[x1][y] + grid[x2][y2] - grid[x1][y2] - grid[x2][y]);
        cost += getCost(x1, y1, x2, y) + getCost(x1, y, x2, y2);
        minCost = min(cost, minCost);
    }
    dp[x1][y1][x2][y2] = minCost;
    // printf("cost of rect %d %d %d %d is %d\n", x1, y1, x2, y2, dp[x1][y1][x2][y2]);

    return dp[x1][y1][x2][y2];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    for (int y = 0; y <= n; y++)
    {
        for (int x = 0; x <= m; x++)
        {
            if (x == 0 || y == 0)
            {
                grid[x][y] = 0;
                continue;
            };
            cin >> c;
            grid[x][y] = grid[x - 1][y] + grid[x][y - 1] + c - grid[x - 1][y - 1];
        }
    }

    printf("%d\n", getCost(0, 0, m, n));

    return 0;
}