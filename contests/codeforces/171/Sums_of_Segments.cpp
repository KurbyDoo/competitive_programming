/*
 * Author: Kurbydoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/2026/D
 * Status: Unsolved
 * Notes:
 *     Created while migrating to github
 *     Original creation date unknown
 *     
 *     
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, li, ri, total = 0, tt = 0;
ll to_n[300010], a[300010];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
        tt += total;
    }

    to_n[1] = tt;
    for (int i = 2; i <= n; i++) {
        to_n[i] = to_n[i - 1] - a[i] * (n - i + 2);
    }
        cin >> q;
    while (q) {
        q--;
        solve();
    }
}