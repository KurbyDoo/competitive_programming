/**
 * Author: KurbyDoo
 * Creation Date: Sep 22, 2025
 * Problem Link: https://atcoder.jp/contests/abc413/tasks/abc413_f
 * Problem Name: F - No Passage
 * Status: Unsolved
 * Notes:
 *
 *
 *
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll h, w, k, ri, ci, ans;
ll grid[3010][3010];
ll visited[3010][3010];
queue<pll> q;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> h >> w >> k;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            grid[i][j] = 999999999;
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> ri >> ci;
        grid[ri][ci] = 0;
        q.push({ri, ci});
        visited[ri][ci] = 2;
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        vector<ll> dx = {1, 0, -1, 0};
        vector<ll> dy = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            if (r + dy[i] < 1 || r + dy[i] > h || c + dx[i] < 1 ||
                c + dx[i] > w)
                continue;
            visited[r + dy[i]][c + dx[i]] += 1;
            if (visited[r + dy[i]][c + dx[i]] == 2) {
                grid[r + dy[i]][c + dx[i]] = grid[r][c] + 1;
                q.push({r + dy[i], c + dx[i]});
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            // printf("%10lld ", grid[i][j]);
            ans += (grid[i][j] == 999999999 ? 0 : grid[i][j]);
        }
        // printf("\n");
    }

    printf("%lld\n", ans);
    return 0;
}