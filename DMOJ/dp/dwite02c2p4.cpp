#include <bits/stdc++.h>
using namespace std;
int dp[5][310][310];
int grid[310][310];
int n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int y = n - 1; y >= 0; y--) {
        for (int x = 0; x < n; x++) {
            cin >> grid[x][y];
            for (int i = 0; i < 5; i++) {
                dp[i][x][y] = INT32_MIN;
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            vector<int> possible;
            if (x == 0 && y == 0) dp[0][x][y] = grid[x][y];
            else if (x == 0) {
                dp[0][x][y] = dp[0][x][y - 1] + grid[x][y];
            } else if (y == 0) {
                dp[0][x][y] = dp[0][x - 1][y] + grid[x][y];
            } else {
                for (int i = 0; i < 5; i++) {
                    possible.push_back(dp[i][x - 1][y]);
                    possible.push_back(dp[i][x][y - 1]);
                }
                sort(possible.begin(), possible.end(), greater<int>());
                for (int i = 0; i < 5; i++) {
                    dp[i][x][y] = possible[i] + grid[x][y];
                }
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d\n", dp[i][n - 1][n - 1]);
    }
    return 0;
}