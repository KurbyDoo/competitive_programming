#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld dp[3010][3010];
int n;
ld nums;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> nums;
        for (int j = 0; j <= i; j++) {
            dp[j][i - j] += dp[j - 1][] * nums + dp[]
        }
    }
}