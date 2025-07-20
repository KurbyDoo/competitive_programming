#include <iostream>
#include <vector>

using std::cin;
using std::vector;

int dp[205][205] = {{0}};

int solve()
{
    // printf("solved callsed\n");
    int n, nCrackers;
    cin >> n >> nCrackers;
    for (int i = 0; i < 205; i++)
    {
        for (int j = 0; j < 205; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    int minValue, maxValue;
    for (int i = 0; i < n; i++)
    {
        // printf("i = %d\n", i);
        cin >> minValue >> maxValue;
        for (int j = 0; j < nCrackers; j++)
        {
            // printf("j = %d\n", j);
            for (int c = minValue; c <= maxValue; c++)
            {
                // printf("c = %d\n", c);
                if (dp[i][j] != 0 && j + c <= nCrackers)
                {
                    dp[i + 1][j + c] += dp[i][j];
                    // printf("possiblility at [%d][%d] from [%d][%d] = %d\n", i + 1, j +c, i, j, dp[i][j]);

                }
            }
            
        }
    }
    // printf("dp [n][nCrackers] = %d\n", dp[n][nCrackers]);
    return dp[n][nCrackers];
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", solve());
        // printf("solve done\n");
    }
    return 0;
}