// Author: KurbyDoo
// Created: 2025-07-07 19:11:05
// IOI '04 P4 - Phidias
// https://dmoj.ca/problem/ioi04p4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int w, h, n;
int wi, hi;
ll dp[610][610];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> w >> h >> n;
    dp[0][0] = 0;
    for (int ww = 0; ww <= w; ww++) {
        for (int hh = 0; hh <= h; hh++) {
            dp[ww][hh] = ww * hh;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> wi >> hi;
        dp[wi][hi] = 0;
    };
    for (int width = 1; width <= w; width++) {
        for (int height = 1; height <= h; height++) {
            for (int cw = 0; cw < width; cw++) {
                dp[width][height] = min(
                    dp[width][height], dp[width - cw][height] + dp[cw][height]);
            }
            for (int ch = 0; ch < height; ch++) {
                dp[width][height] = min(dp[width][height],
                                        dp[width][height - ch] + dp[width][ch]);
            }
        }
    }
    // for (int ww = 0; ww <= w; ww++) {
    //     for (int hh = 0; hh <= h; hh++) {
    //         printf("%5d%s", dp[ww][hh], hh == h ? "\n" : " ");
    //     }
    // }
    printf("%lld\n", dp[w][h]);
    return 0;
}