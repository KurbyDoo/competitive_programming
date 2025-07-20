#include <iostream>
#include <vector>
#include <cstring>

using std::cin;
using std::vector;
using std::min;
using std::max;

typedef signed long long ll;

ll dp[3005][3005];
int n;
vector<ll> stones;

ll solve(int l, int r)
{
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    ll left = stones[l] + min(solve(l + 1, r - 1), solve(l + 2, r));
    ll right = stones[r] + min(solve(l + 1, r - 1), solve(l, r - 2));
    dp[l][r] = max(left, right);
    return dp[l][r];
}

int main()
{
    cin >> n;
    ll s;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sum = sum + s;
        // printf("s = %d\n", s);
        stones.push_back(s);
    }

    memset(dp, -1, sizeof(dp));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    ll maxX = solve(0, n - 1);

    // printf("maxX = %lld\n", maxX);
    // printf("sum = %lld\n", sum);
    printf("%lld\n", maxX * 2 - sum);

    return 0;
}