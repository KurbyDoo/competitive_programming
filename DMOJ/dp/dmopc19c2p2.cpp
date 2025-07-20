    #include <bits/stdc++.h>
    using namespace std;
    int dp[510][510];
    int costs[510][510];
    int n, m;
    int main() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> costs[i][j];
                dp[i][j] = 999999999;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) dp[i][j] = costs[i][j];
                else if (i == 1) dp[i][j] = dp[i][j - 1] + costs[i][j];
                else if (j == 1) dp[i][j] = dp[i - 1][j] + costs[i][j];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + costs[i][j];
            }
        }
        printf("%d\n", dp[n][m]);
    }
