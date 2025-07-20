/*
 * Author: KurbyDoo
 * Creation Date: Jul 20, 2025
 * Problem Link: https://atcoder.jp/contests/abc405/tasks/abc405_e
 * Problem Name: E - Fruit Lineup 
 * Status: Solved
 * Notes:
 * 	Break into sections [a/o1][o2/b/g]
 * 	Fix o1 where o2 = o - o1
 * 	Assume [a/o1] ends with a
 * 	t1 = (a + o1 - 1)!/(a - 1)!o1!
 *  let s = o2 + b + g
 *  t2 = s!/(s - b)!b!
 * 
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
ll a, b, c, d, ans = 0;
vector<ll> fact;
vector<ll> inv_fact;

ll quickpow(ll n, ll exp, ll mod) {
    if (exp == 0) return 1LL;
    ll res = quickpow(n, exp / 2, mod);
    return (((res * res) % mod) * (exp % 2 ? n : 1LL)) % mod;
}

void populate_factorial(ll max_val, ll mod, vector<ll>& _fact, vector<ll>& _inv_fact) {
    _fact.resize(max_val + 1);
    _inv_fact.resize(max_val + 1);
    _fact[0] = 1;
    _inv_fact[0] = 1;
    for (ll i = 1; i <= max_val; i++) {
        _fact[i] = _fact[i - 1] * i % mod;
    }
    _inv_fact[max_val] = quickpow(_fact[max_val], mod - 2, mod);
    for (ll i = max_val; i > 1; i--) {
        _inv_fact[i - 1] = _inv_fact[i] * i % mod;
    }
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> a >> b >> c >> d;
    populate_factorial(a + b + c + d, MOD, fact, inv_fact);

    for (ll o1 = 0; o1 <= b; o1++) {
        ll t1 = 1, t2 = 1;
        ll o2 = b - o1;
        if (a != 0) {
            t1 = fact[a - 1 + o1] * inv_fact[a - 1] % MOD * inv_fact[o1] % MOD;
        }
        t2 = fact[o2 + c + d] * inv_fact[o2 + d] % MOD * inv_fact[c] % MOD;
        // printf("o1 = %lld o2 = %lld : t1 = %lld t2 = %lld\n", o1, o2, t1, t2);
        ans = (ans + t1 * t2 % MOD) % MOD;
    }

    printf("%lld\n", ans);
    
    return 0;
}