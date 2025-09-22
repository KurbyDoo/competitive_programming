#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll A, B, x;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> A >> B;

    // # t(x) = A(g + x)^{-1/2} + Bx
    // # t'(x) = A(-1/2)(g + x)^{-3/2} + B = 0
    // # -B = A(-1/2)(g + x)^{-3/2}
    // # (g + x)^{3/2} = A/(2B)
    // # (g + x)^3 = (A/(2B))^2
    // # x = (A/(2B))^{2/3} - g
    x = powl(((long double)A) / (2.0L * B), 2.0L / 3.0L) - 1;
    long double ans = 1.0L << __SIZEOF_LONG_DOUBLE__;
    ll low = max(0LL, x - 1);
    for (ll i = low; i <= low + 3; i++) {
        long double total = A / sqrtl(1LL + i) + B * i;
        ans = min(total, ans);
    }
    printf("%9Lf\n", ans);

    return 0;
}