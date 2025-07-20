#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n;
ll value[300010];
ll dp[300010];
ll preSum[300010];
ll inv(ll a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}

ll frac_mod(ll x, ll y)
{
    return inv((y * inv(x)) % mod);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ll total = 0;
        // for (int j = i + 1; j < n; j++)
        // {
        //     total = (total + frac_mod(dp[j], n)) % mod;
        // }
        total = preSum[i + 1];
        total += value[i];
        dp[i] = total % mod;
        preSum[i] = preSum[i + 1] + frac_mod(dp[i], n);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + frac_mod(dp[i], n)) % mod;
        // printf("%d ", dp[i]);
    }
    // printf("\n");
    printf("%lld\n", ans);

    // cout << inv(49) << "\n";
    // cout << frac_mod(49, 9) << "\n";
    // cout << frac_mod(19, 9) + frac_mod(12, 9) + frac_mod(18, 9) << '\n';
}