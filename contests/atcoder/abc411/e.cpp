/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://atcoder.jp/contests/abc411/tasks/abc411_e
 * Problem Name: E - E [max]
 * Status: Solved
 * Notes:
 *     Iterate through all dice faces from max -> least
 *     Keep track of how many dice faces are less than current
 *     Get product of all dice except for current face
 *     Update current face by -1
 */

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;

ll rem_face[100010];
ll tree[400010];
void build(ll i, ll l, ll r) {
    if (l == r) {
        tree[i] = 6;
        rem_face[l] = 6;
        return;
    }
    ll mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
}

void update(ll i, ll l, ll r, ll pos) {
    if (l == pos && pos == r) {
        tree[i] -= 1;
        rem_face[l] -= 1;
        return;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid) update(i * 2, l, mid, pos);
    else update(i * 2 + 1, mid + 1, r, pos);
    tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
}

ll query(ll i, ll l, ll r, ll ql, ll qr) {
    if (l == ql && r == qr) {
        return tree[i];
    }
    ll mid = (l + r) / 2;
    if (qr <= mid) return query(i * 2, l, mid, ql, qr);
    else if (mid < ql) return query(i * 2, mid + 1, l, ql, qr);
    return (query(i * 2, l, mid, ql, mid) * query(i * 2 + 1, mid + 1, r, mid + 1, qr)) % MOD;
}

ll quickpow(ll n, ll exp, ll mod) {
    if (exp == 0) return 1LL;
    ll res = quickpow(n, exp / 2, mod);
    return (((res * res) % MOD) * (exp % 2 ? n : 1LL)) % MOD;
}

ll n, ai;
vector<pll> dices;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> n;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            cin >> ai;
            dices.emplace_back(ai, i);
        }
    }
    sort(dices.begin(), dices.end(), greater<pll>());
    
    ll ans = 0;
    for (auto [face, id]: dices) {
        ll total_prob = query(1, 1, n, 1, n);
        ll possible = (total_prob * quickpow(rem_face[id], MOD - 2, MOD)) % MOD;
        // printf("%lld %lld : %lld / %lld = %lld\n", face, id, total_prob, rem_face[id], possible);
        ans = (ans + (possible * face) % MOD) % MOD;
        update(1, 1, n, id);
    }
    // printf("%lld\n", ans);
    ans = (ans * quickpow(6, n * (MOD - 2), MOD)) % MOD;
    printf("%lld\n", ans);
    
    return 0;
}