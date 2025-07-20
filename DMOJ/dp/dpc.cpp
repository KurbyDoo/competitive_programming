#include <iostream>

using std::cin;
using std::max;

int n;
int a, b, c;
int points[100005][3];
int dp[100005][3];


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        points[i][0] = a;
        points[i][1] = b;
        points[i][2] = c;
    }

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][2] + points[i][2], dp[i][1] + points[i][1]);
        dp[i + 1][1] = max(dp[i][2] + points[i][2], dp[i][0] + points[i][0]);
        dp[i + 1][2] = max(dp[i][0] + points[i][0], dp[i][1] + points[i][1]);
    }

    printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][1])));
    return 0;
}