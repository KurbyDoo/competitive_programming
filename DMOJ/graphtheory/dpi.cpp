#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double dp[3010][3010];
double chance;
int n;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> chance;
        for (int j = 0; j <= n; j++) {
            dp[i + 1][j] += dp[i][j] * (1.0 - chance);
            dp[i + 1][j + 1] += dp[i][j] * chance;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%f ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    double total = 0;
    for (int i = n; i > n - i; i--) {
        total += dp[n][i];
    }
    printf("%.9f\n", total);
    return 0;
}