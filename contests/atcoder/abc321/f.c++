# include <bits/stdc++.h>

using std::cin;
typedef long long ll;
const int mod = 998244353;

ll dp[5010];
int q, k, x;
char op;
int main() {
    cin >> q >> k;
    dp[0] = 1;
    for (int i = 0; i < q; i++) {
        // printf("i = %d\n", i);
        cin >> op >> x;
        if (op == '+') {
            for (int i = k; i >= x; i--) {
                dp[i] += dp[i - x];
                dp[i] %= mod;
            }
        } else {
            for (int i = x; i <= k; i++) {
                dp[i] -= dp[i - x] - mod;
                dp[i] %= mod;
            }
        }
        printf("%llu\n", dp[k] % mod);
    }
    return 0;
}