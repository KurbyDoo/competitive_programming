/**
 * Author: KurbyDoo
 * Creation Date: Jul 28, 2025
 * Problem Link: https://atcoder.jp/contests/abc415/tasks/abc415_e
 * Problem Name: E - Hungry Takahashi
 * Status: Unsolved / Read editorial
 * Notes:
 *      Spend too much time trying to figure out
 *      how to find dp state that represents
 *      best val from start -> cur pos
 *      Instead, should focus on best val that 
 *      represents cur pos -> end
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef array<ll, 3> val;

ll h, w, ai;
vector<ll> rows[200010];
vector<ll> dp[200010];
vector<ll> extra[200010];
vector<ll> pk;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        rows[i].resize(w + 1);
        dp[i].resize(w + 1);
        memset(dp[i], -1, sizeof(dp[i]));
        for (int j = 1; j <= w; j++) {
            cin >> rows[i][j];
        }
    }

    pk.resize(h + w);
    for (int i = 1; i <= h + w - 1; i++) {
        cin >> pk[i];
    }

    dp[h][w] = 0;
    for (int i = h; i > 0; i--) {
        for (int j = w; j > 0; j--) {
            // TODO: Fill
        } }
    printf("%lld\n", dp[h][w]);

    return 0;
}