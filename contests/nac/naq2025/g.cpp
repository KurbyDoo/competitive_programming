#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int MOD = 998244353;
ll n, k;

ll quickpow(ll base, ll exp, ll mod) {
    if (exp == 0) return 1LL;
    ll res = quickpow(base, exp / 2, mod);
    return (((res * res) % mod) * (exp % 2 ? base : 1LL)) % mod;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    // 2k + 1 choices per room
    // need exact 1, P(x = 1) = (2k + 1) * (1/2k + 1) * (1 - 1(2k + 1)) ^ (2k)
    // (2k + 1) - 1 / (2k + 1)
    cin >> n >> k;
    ll numerator = quickpow(2 * k, 2 * k, MOD);
    ll denom = quickpow(2 * k + 1, 2 * k, MOD);
    ll ans = numerator * quickpow(denom, MOD - 2, MOD) % MOD * n % MOD;
    printf("%lld\n", ans);
    printf("%lld/%lld\n", numerator * n, denom);
    return 0;
}