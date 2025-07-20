#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dp[2010][2010];
ll actual[2010];
ll expt[2010];
int n, m;

int score(int real, int given) {
    ll diff = abs(expt[real] - actual[given]);
    if (diff <= 15) return 7;
    if (diff <= 23) return 6;
    if (diff <= 43) return 4;
    if (diff <= 102) return 2;
    return 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> expt[i + 1];
    }
    for (int i = 0; i < m; i++) {
        cin >> actual[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + score(i, j), dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);

    return 0;
}