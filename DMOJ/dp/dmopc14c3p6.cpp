// Kurbydoo
// Feb 12th, 2023
// Valentine's Day '15 P2 - Simon and Marcy
// https://dmoj.ca/problem/valday15p2

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::max;
using std::pair;
using std::unordered_map;
using std::vector;

typedef long long ll;

int n, t;
ll p1, v1, p2, v2, p3, v3;

ll dp[10100];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> t;

    for (int i = 0; i <= t; i++)
    {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {

        cin >> p1 >> v1 >> p2 >> v2 >> p3 >> v3;
        for (int j = t; j >= 0; j--)
        {
            ll best = dp[j];
            if (j - p1 >= 0) {
                best = max(best, dp[j - p1] + v1);
            }

            if (j - p2 >= 0)
            {
                best = max(best, dp[j - p2] + v2);
            }

            if (j - p3 >= 0)
            {
                best = max(best, dp[j - p3] + v3);
            }

            dp[j] = best;

        }
        // printf("[");
        // for (int j = 0; j <= t; j++)
        // {
        //     printf("%d ", dp[j]);
        // }
        // printf("]\n");
    }

    printf("%d\n", dp[t]);

    return 0;
}