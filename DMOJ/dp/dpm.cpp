#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
const ll mod = 1e9 + 7;
int children[105];
ll dp[100010];
ll psa[100010];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> children[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        psa[1] = dp[0];
        for (int j = 2; j <= k + 1; j++)
        {
            psa[j] = (psa[j - 1] + dp[j - 1]) % mod;
        }
        for (int j = 0; j <= k; j++)
        {
            dp[j] = (psa[j + 1] - psa[max(j - children[i], 0)] + mod) % mod;
        }
    }
    printf("%d\n", dp[k]);
}