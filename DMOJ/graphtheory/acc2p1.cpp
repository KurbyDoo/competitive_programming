#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1000000000000000;
ll dist[110][110];
ll dp[110][110][110];
ll n, q, ei, ai, bi, ci;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ei;
            dist[i][j] = ei == 0 ? INF : ei;
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dp[i][j][1] = dist[i][j];
            }
        }
    }

    for (int d = 2; d < n; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j][d] = INF;
                for (int k = 1; k <= n; k++) {
                    dp[i][j][d] = min(dp[i][j][d], max(dp[i][k][d - 1], dist[k][j]));
                }
                // printf("%d %d %d set to %d\n", i, j, d, dp[i][j][d]);
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> ai >> bi >> ci;
        printf("%lld\n", dp[ai][bi][ci] == INF ? 0 : dp[ai][bi][ci]);
    }
        return 0;
}