#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t, l, r, a, b, c;
ll daA[100010];
ll daB[100010];
ll daC[100010];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r >> a >> b >> c;
        // a(x - l) ^ 2 + b(x - l) + c;
        // a(x ^ 2 - 2lx + l ^ 2) + bx - bl + c;
        // ax ^ 2 - 2lax + al ^ 2 + bx - bl + c;
        // a(x ^ 2) + (b - 2al) x + (al ^ 2 - bl + c);
        daA[l] += a;
        daB[l] += b - 2 * l * a;
        daC[l] += a * l * l - b * l + c;
        daA[r + 1] -= a;
        daB[r + 1] -= b - 2 * l * a;
        daC[r + 1] -= a * l * l - b * l + c;
    }
    for (ll i = 1; i < t; i++) {
        daA[i] += daA[i - 1];
        daB[i] += daB[i - 1];
        daC[i] += daC[i - 1];
        printf("%lld ", daA[i] * i * i + daB[i] * i + daC[i]);
    }
    daA[t] += daA[t - 1];
    daB[t] += daB[t - 1];
    daC[t] += daC[t - 1];
    printf("%lld\n", daA[t] * t * t + daB[t] * t + daC[t]);
}