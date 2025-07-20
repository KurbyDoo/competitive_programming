#include <iostream>

int dp[105][105] = {0};
int grid[105][105] = {0};
int maxValue = 0;

using std::cin;
using std::max;

int main()
{
    int n;
    cin >> n;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= y; x++)
        {
            cin >> grid[y][x];
        }
    }

    dp[1][1] = grid[1][1];
    for (int y = 2; y <= n; y++) dp[y][1] = dp[y - 1][1] + grid[y][1];
    for (int y = 2; y <= n; y++)
    {
        for (int x = 2; x <= y; x++)
        {
            dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + grid[y][x];
            maxValue = max(dp[y][x], maxValue);
        }
    }

    printf("%d\n", maxValue);
    return 0;
}