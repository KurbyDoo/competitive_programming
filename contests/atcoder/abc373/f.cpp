#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[3010];
ll n, w, a, b;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        for (int wi = w; wi >= 0; wi--) {
            ll max_amount = wi / a;
            for (int j = 1; wi - j * a >= 0; j++) {
                dp[wi] = max(dp[wi], dp[wi - j * a] + j * b - j * j);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= w; i++) {
        ans = max(dp[i], ans);
    }
    printf("%lld\n", ans);

        return 0;
}