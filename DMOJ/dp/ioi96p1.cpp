#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
int score[110][110];
int n, total;
int nums[110];
int play(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r]) return dp[l][r];
    return dp[l][r] = max(nums[l] - play(l + 1, r), nums[r] - play(l, r - 1));
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    play(0, n - 1);
    // printf("%d %d\n", dp[0][n - 1], max(dp[1][n - 1], dp[0][n - 2]));
    printf("%d %d\n", (total - dp[0][n - 1]) / 2 + dp[0][n - 1], (total - dp[0][n - 1]) / 2);
}