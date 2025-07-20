#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<ll, double> dp;
ll n, a, x, y;

double dfs(ll num)
{
    if (num == 0)
        return 0.0;
    if (dp[num] != 0)
        return dp[num];

    double expected = dfs(num / a) + x;
    double dice = 0; // = (d2..5 + 5y) * 1/6 + (dice + y) * 1/6
    // dice (5/6) = (d2..5) * 1/6 + 5/6 y + y * 1/6
    // dice = (d2..5) / 5 + y + y * 1/5
    // dice = (d2..5) / 5 + 1.2y
    dice += dfs(num / 2);
    dice += dfs(num / 3);
    dice += dfs(num / 4);
    dice += dfs(num / 5);
    dice += dfs(num / 6);
    // printf("dice: %f, norm: %f\n", dice / 5.0 + 1.2 * y, expected);
    dp[num] = min(dice / 5 + 1.2 * y, expected);
    // printf("calculated %f for %d\n", dp[num], num);
    return dp[num];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> a >> x >> y;

    printf("%f\n", dfs(n));
}