#include <iostream>
#include <algorithm>
#include <vector>

using std::min;
using std::cin;
using std::sort;
using std::pair;
using std::vector;
using std::greater;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> players;
ll dp[5010][5010];
int n, m;
ll a, b;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        players.push_back({a, b});
    }
    sort(players.begin(), players.end(), greater<pll>());

    // for (pll e: players) {
    //     printf("%llu, %llu\n", e.first, e.second);
    // }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            dp[w][i] = 500000000000000000;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                if (i > 0) {
                    dp[w][i] = dp[w][i - 1];
                }

                continue;
            }

            dp[w][i] = min(dp[w][i - 1], dp[w - 1][i - 1] + players[i - 1].first * (w - 1) + players[i - 1].second);
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int w = 0; w <= m; w++) {
    //         printf("%llu ", dp[w][i]);
    //     }
    //     printf("\n");
    // }

    printf("%llu\n", dp[m][n]);

    return 0;

}

// 5 3
// 1 1
// 2 2
// 3 3
// 4 4
// 5 5
// best = 10

// 3 3
// 10 1
// 2 4
// 3 3
// best = 15
