/**
 * Author: KurbyDoo
 * Creation Date: Sep 11, 2025
 * Problem Link: https://codeforces.com/contest/2140/problem/C
 * Problem Name: C. Ultimate Value
 * Status: Unsolved
 * Notes:
 *  - Cost is increasing, would bob ever want to take two swaps?
 *  - No? Since alice can always swap back the first swap (assuming you always
 *        make first swap best swap)
 *  - Would bob ever want to make one swap? NO?
 *  - So find the move that maximizes alice score
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll t, n, a[200010];

void solve() {
    priority_queue<pll> max_vals;
    priority_queue<pll> min_vals;
    ll ans = 0;
    cin >> n;
    ans = n % 2 ? n - 1 : n - 2;
    ll i1 = ans, i2 = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2) {
            // min
            if (!min_vals.empty()) {
                if (min_vals.top().first + 2 * a[i] + i > ans) {
                    ans = max(ans, min_vals.top().first + 2 * a[i] + i);
                    i1 = i;
                    i2 = min_vals.top().second;
                }
            }

            max_vals.push({2 * a[i] - i, i});

        } else {
            // max
            if (!max_vals.empty()) {
                if (max_vals.top().first - 2 * a[i] + i > ans) {
                    ans = max(ans, max_vals.top().first - 2 * a[i] + i);
                    i1 = i;
                    i2 = max_vals.top().second;
                }
            }

            min_vals.push({-2 * a[i] - i, i});
        }

        // printf("ans = %d\n", ans);
    }
    if (i1 != i2) {
        a[i1] ^= a[i2];
        a[i2] ^= a[i1];
        a[i1] ^= a[i2];
    }

    ans = i1 - i2;
    for (ll i = 0; i < n; i++) {
        // printf("%lld ", a[i]);
        ans += i % 2 ? -a[i] : a[i];
    }
    printf("%lld\n", ans);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    while (t--) solve();

    return 0;
}