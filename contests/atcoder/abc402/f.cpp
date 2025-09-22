/**
 * Author: KurbyDoo
 * Creation Date: Jul 22, 2025
 * Problem Link: https://atcoder.jp/contests/abc402/tasks/abc402_f
 * Problem Name: F - Path to Integer
 * Status: Unsolved / Read editorial
 * Notes:
 * 	Brute force?
 * 	Meet in the middle + binary search
 *  Recursion too slow!!!
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef array<ll, 3> trip;
ll n, m, ans = 0;
ll grid[30][30];
vector<ll> diag1[30];
vector<ll> diag2[30];

ll quickpow(ll base, ll exp, ll mod) {
    if (exp == 0) return 1LL;
    ll res = quickpow(base, exp / 2, mod);
    return (((res * res) % mod) * (exp % 2 ? base : 1LL)) % mod;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            cin >> grid[r][c];
            grid[r][c] = (grid[r][c] * quickpow(10, 2 * n - r - c, m)) % m;
        }
    }

    for (int mask = 0; mask <= (1 << n) - 1; mask++) {
        ll x = 1, y = 1;
        ll cur = grid[x][y];
        for (int i = 0; i < n - 1; i++) {
            if ((mask >> i) & 1) x++;
            else y++;
            cur = (cur + grid[x][y]) % m;
        }
        diag1[x].push_back(cur);
    }

    for (int mask = 0; mask <= (1 << n) - 1; mask++) {
        ll x = n, y = n;
        ll cur = 0;
        for (int i = 0; i < n - 1; i++) {
            cur = (cur + grid[x][y]) % m;
            if ((mask >> i) & 1) x--;
            else y--;
        }
        diag2[x].push_back(cur);
    }

    for (int i = 1; i <= n; i++) {
        sort(diag2[i].begin(), diag2[i].end());
        // for (ll v : diag1[i]) printf("%d ", v);
        // printf("\n");
        // for (ll v : diag2[i]) printf("%d ", v);
        // printf("\n");

        for (ll d1 : diag1[i]) {
            auto itr = lower_bound(diag2[i].begin(), diag2[i].end(), m - d1);
            ll val =
                itr == diag2[i].begin() ? *(diag2[i].end() - 1) : *(itr - 1);
            // printf("found val %d %d\n", d1, val);
            ans = max(ans, (d1 + val) % m);
        }
    };

    printf("%lld\n", ans);

    return 0;
}