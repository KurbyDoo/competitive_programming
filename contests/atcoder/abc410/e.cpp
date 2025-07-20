// Author: KurbyDoo
// Created: 2025-06-16 20:34:21
// Battles in a Row
// https://atcoder.jp/contests/abc410/tasks/abc410_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n, h, m;
int dp[3010][3010];
int health[3010];
int magic[3010];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> h >> m;
    for (int i = 0; i < n; i++) {
        cin >> health[i] >> magic[i];
        for (int mana = m; mana >= 0; mana--) {
            dp[i][mana] = -999999999;
            dp[i + 1][mana] = -999999999;
        }
    }

    int ans = 0;
    dp[0][m] = h;
    for (int i = 0; i <= n; i++) {
        for (int mana = m; mana >= 0; mana--) {
            if (mana - magic[i] >= 0)
                dp[i + 1][mana - magic[i]] =
                    max(dp[i + 1][mana - magic[i]], dp[i][mana]);
            dp[i + 1][mana] = max(dp[i + 1][mana], dp[i][mana] - health[i]);
            if (dp[i][mana] >= 0) ans = max(i, ans);
        }
    }

    printf("%d\n", ans);
    return 0;
}