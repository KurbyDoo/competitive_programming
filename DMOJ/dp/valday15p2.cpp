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

int c, m;
int dp[1010][1010];
int amount[1010];
int cost[1010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> c >> m;
    for (int i = 0; i < c; i++) {
        cin >> amount[i];
        cin >> cost[i];
    }

    for (int i = 0; i <= c; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (cost[i] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else if (i > 0 && w >= cost[i]) {
                dp[i][w] = max(amount[i] + dp[i - 1][w - cost[i]], dp[i - 1][w]);
            }
        }
    }

    // for (int i = 0; i <= c; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

        printf("%d\n", dp[c][m]);
    return 0;
}