#include <bits./stdc++.h>
typedef long long ll;
const ll NN = 2e5;
ll fact[NN + 10];
ll ifact[NN + 10];
ll MOD = 998244353;

ll binPow(ll base, ll exp) {
    ll ans = 1;
    while (exp) {
        if (exp % 2) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return ans;
}

// N is small
ll nCk(ll N, ll K) {
    if (K > N || K < 0) return 0;
    return (fact[N] * ((ifact[K] * ifact[N - K]) % MOD)) % MOD;
}

// k is small
ll nCk2(ll N, ll K) {
    if (K > N || K < 0) return 0;
    return ((N * nCk2(N - 1, K - 1) % MOD) * binPow(K, MOD - 2)) % MOD
}

void ICombo() {
    fact[0] = 1;
    for (int i = 1; i <= NN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ifact[NN] = binPow(fact[NN], MOD - 2);
    for (int i = NN - 1; i >= 0; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
    }
}