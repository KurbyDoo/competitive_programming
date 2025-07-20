#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[110][10010];
ll a[110], b[110], c[110], d[110];
ll n, x;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0
        for (int j = 0; j <= 10000; j++) {
            ll cost = 1000000000;
            if (j - a[i] >= 0) {
                cost = min(cost, dp[i][j - a[i]] + b[i]);
            }
            if (j - c[i] >= 0) {
                cost = min(cost, dp[i - 1][j - c[i]] + d[i]);
                cost = min(cost, dp[i][j - c[i]] + d[i]);
            }
            dp[i][j] = cost;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 10; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

        return 0;
}