#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll grid[1510][1510];
ll dp[1510][1510];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> order;

int n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            order.push({grid[i][j], {i, j}});
        }
    }

    while (!order.empty())
    {
        int x = order.top().second.first, y = order.top().second.second;
        // printf("doing %d at %d %d\n", order.top().first, x, y);
        order.pop();
        if (x >= 1 && grid[x - 1][y] > grid[x][y]) {
            dp[x - 1][y] = max(dp[x - 1][y], dp[x][y] + 1);
        }
        if (x < n - 1 && grid[x + 1][y] > grid[x][y])
        {
            dp[x + 1][y] = max(dp[x + 1][y], dp[x][y] + 1);
        }
        if (y >= 1 && grid[x][y - 1] > grid[x][y])
        {
            dp[x][y - 1] = max(dp[x][y - 1], dp[x][y] + 1);
        }
        if (y < n - 1 && grid[x][y + 1] > grid[x][y])
        {
            dp[x][y + 1] = max(dp[x][y + 1], dp[x][y] + 1);
        }
    }

    ll big = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            big = max(dp[i][j], big);
        }
    }
    printf("%lld\n", big);
}