#include <iostream>

using std::abs;
using std::cin;
using std::min;

typedef long long ll;

ll dp[100010];
int value[1010];
ll weight[1010];
ll t;
int n;
int maxValue = 0;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
        maxValue += value[i];
    }

    for (int i = 0; i <= maxValue; i++)
    {
        dp[i] = 10000000000000;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (ll v = maxValue; v >= value[i]; v--)
        {
            dp[v] = min(dp[v - value[i]] + weight[i], dp[v]);
        }
    }

    // for (int i = 0; i <= maxValue; i++)
    // {
    //     printf("(%llu, %d) ", dp[i], i);
    // }
    for (int i = maxValue; i >= 0; i--)
    {
        if (dp[i] <= t)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}