// Kurbydoo
// May 24th, 2023
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using std::cin;
using std::max;
using std::memset;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;
ll n;
ll players[17][17];
ll dp[17][1 << 17];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> players[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1 << n; j++)
        {
            dp[i][j] = -10000000000000000;
        }
    }
    // memset(dp, 10000000000000000, sizeof(dp));

    for (int mask = 0; mask < 1 << n; mask++) {

    }
        // for (int mask = 0; mask < 1 << n; mask++)
        // {
        //     printf("mask = %d = %lld\n", mask, dp[n - 1][mask]);
        // }
        return 0;
}