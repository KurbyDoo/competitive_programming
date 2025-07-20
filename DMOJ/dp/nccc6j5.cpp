// Kurbydoo
// Feb 22, 2023
// Mock CCC '19 Contest 1 J5 - Pusheen Designs a Sushi Boat
// https://dmoj.ca/problem/nccc6j5
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;

typedef long long ll;

int n, k;
int a;
int sushi[1010];

ll dp[1010][1010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        sushi[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sushi[a]++;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    // dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (dp[i - 1][j] + sushi[i] * dp[i - 1][j - 1]) % 998244353;
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         printf("%llu ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%llu\n", dp[n][k]);

    return 0;
}