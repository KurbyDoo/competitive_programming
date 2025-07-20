#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, ai[100010];
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    cin >> n;
    ll d = 0;
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
        d = gcd(ai[i], d);
    }

    for (int i = 0; i < n; i++) {
        ai[i] = ai[i] / d;
    }

        ll ans = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur == 1) {
            ans += n - i;
            break;
        }
        ll best = 9999999999999;
        for (int j = 0; j < n; j++) {
            best = min(best, gcd(ai[j], cur));
        }

        cur = best;
        ans += cur;
        // printf("cur= %lld\n", cur);
    }
    printf("%lld\n", d * ans);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (; t > 0; t--) {
        solve();
    }
}