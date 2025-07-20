# include <bits/stdc++.h>

using std::cin;
using std::memset;
using std::min;
using std::max;
typedef long long ll;

ll dp[71][71][71];
ll edges[71][71];

int n, m, k, q, a, b, c;
int main() {
    cin >> n >> m;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= n; z++) {
                dp[x][y][z] = y == z ? 0 : INT32_MAX;
            }
            edges[x][y] = INT32_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[a][b] = edges[a][b] > c ? c : edges[a][b];
        // edges[b][a] = c;
    }
    cin >> k >> q;


    for (int i = 1; i <= k; i++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                for (int z = 1; z <= n; z++) {
                    if (dp[i - 1][x][z] == INT32_MAX || edges[z][y] == INT32_MAX) continue;
                    dp[i][x][y] = min(dp[i][x][y], min(dp[i - 1][x][y], dp[i - 1][x][z] + edges[z][y]));

                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        printf("%lld\n", dp[k][a][b] != INT32_MAX ? dp[k][a][b] : -1);
    }
    return 0;
}
// 2 3
// 1 2 3
// 2 1 99
// 1 2 