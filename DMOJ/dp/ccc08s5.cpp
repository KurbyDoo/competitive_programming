// Kurbydoo
// July 7th, 2025
// CCC '08 S5 - Nukit
// https://dmoj.ca/problem/ccc08s5
#include <bits/stdc++.h>

using namespace std;
int dp[35][35][35][35];
int n, a, b, c, d;

bool dfs(int ca, int cb, int cc, int cd) {
    if (ca < 0 || cb < 0 || cc < 0 || cd < 0) return true;
    if (dp[ca][cb][cc][cd] != -1) return dp[ca][cb][cc][cd];

    return dp[ca][cb][cc][cd] =
               (!dfs(ca - 2, cb - 1, cc, cd - 2) ||
                !dfs(ca - 1, cb - 1, cc - 1, cd - 1) ||
                !dfs(ca, cb, cc - 2, cd - 1) || !dfs(ca, cb - 3, cc, cd) ||
                !dfs(ca - 1, cb, cc, cd - 1));
}

void solve() {
    cin >> a >> b >> c >> d;
    bool patrick_wins = dfs(a, b, c, d);
    printf(patrick_wins ? "Patrick\n" : "Roland\n");
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}