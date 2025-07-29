/**
 * Author: KurbyDoo
 * Creation Date: Jul 22, 2025
 * Problem Link: https://atcoder.jp/contests/abc402/tasks/abc402_f
 * Problem Name: F - Path to Integer 
 * Status: Unsolved / Read editorial
 * Notes:
 * 	Brute force?
 * 	Meet in the middle + binary search
 * 	
 * 	
**/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef array<ll, 3> trip;
ll n, m, ans = 0;
ll grid[30][30];

ll quickpow(ll base, ll exp, ll mod) {
    if (exp == 0) return 1LL;
    ll res = quickpow(base, exp / 2, mod);
    return (((res * res) % mod) * (exp % 2 ? base : 1LL)) % mod;
}

void dfs(int x, int y, ll depth, ll cur) {
    cur = (cur + grid[y][x] * quickpow(10, depth, m)) % m;
    if (x + 1 <= n) dfs(x + 1, y, depth - 1, cur);
    if (y + 1 <= n) dfs(x, y + 1, depth - 1, cur);
    if (x == n && y == n) ans = max(ans, cur);
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            cin >> grid[r][c];
        }
    }

    dfs(1, 1, 2 * n - 2, 0);
    printf("%lld\n", ans);
    
    return 0;
}