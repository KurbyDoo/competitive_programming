#include <bits/stdc++.h>
using namespace std;

int n, k, c;
bool dp[200010];
int candies[51000];
int total = 0;
// too hard
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> c;
        k %= 2;
        candies[i] = c * k;
        total += candies[i];
    }

    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 200000; j >= 0; j--) {
            if (dp[j]) dp[j + candies[i]] = true;
        }
    }


    int ans = total;
    for (int i = 0; i <= 200000; i++) {
        if (dp[i]) ans = min(ans, abs(i - (total - i)));
    }
    printf("%d\n", ans);
}