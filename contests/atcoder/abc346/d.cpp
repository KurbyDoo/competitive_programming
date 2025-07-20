#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[200010][4];
ll costs[200010];
int n;
string s;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
        dp[i][0] = 200000000000000;
        dp[i][1] = 200000000000000;
        dp[i][2] = 200000000000000;
        dp[i][3] = 200000000000000;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 200000000000000;
    dp[0][3] = 200000000000000;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + costs[i];
            if (i > 1) {
                dp[i][2] = min(dp[i - 1][3], dp[i - 1][0]);
                dp[i][3] = min(dp[i - 1][2] + costs[i], dp[i - 1][1] + costs[i]);
            }
        } else {
            dp[i][0] = dp[i - 1][1] + costs[i];
            dp[i][1] = dp[i - 1][0];
            if (i > 1) {
                dp[i][2] = min(dp[i - 1][3] + costs[i], dp[i - 1][0] + costs[i]);
                dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]);
            }
        }
        // printf("%d %d %d %d\n", dp[i][0], dp[i][1], dp[i][2], dp[i][3]);
    }
    printf("%lld\n", min(dp[n][2], dp[n][3]));

    return 0;
}