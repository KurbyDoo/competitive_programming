#include <iostream>

using std::abs;
using std::cin;
using std::max;

int dp[1010][1010];
int value[1010];
int weight[1010];
int n, t;
int v, w;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        cin >> weight[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= t; w++)
        {
            if (w == 0 || i == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else if (i > 0 && w >= weight[i])
            {
                dp[i][w] = max(value[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            }
        }
    }

    printf("%d\n", dp[n][t]);
    return 0;
}
