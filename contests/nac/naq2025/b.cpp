#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
queue<tuple<ll, ll, ll, ll>> q;
ll ROWS, COLS, n, a, b;
pll grid[510][510][2];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> ROWS >> COLS >> n;
    for (int i = 1; i <= ROWS; i++) {
        for (int j = 1; j <= COLS; j++) {
            grid[i][j][0] = {0, 999999};
            grid[i][j][1] = {0, 999999};
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        grid[a][b][0] = {i, 0};
        q.push({a, b, i, 0});
    }

    while (!q.empty()) {
        auto [r, c, t, d] = q.front();
        q.pop();
        printf("at %d %d %d %d\n", r, c, t, d);
        vector<ll> dx = {1, 0, -1, 0};
        vector<ll> dy = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            ll nr = r + dx[i], nc = c + dy[i];
            if (nr == 0 || nc == 0 || nr == ROWS + 1 || nc == COLS + 1) continue;
            if (grid[nr][nc][0].second > d + 1) {
                grid[nr][nc][1] = grid[nr][nc][0];
                grid[nr][nc][0] = {t, d + 1};
                q.push({nr, nc, t, d + 1});
            } else if (grid[nr][nc][0].second == d + 1 &&
                       grid[nr][nc][0].first > t) {
                grid[nr][nc][1] = grid[nr][nc][0];
                grid[nr][nc][0] = {t, d + 1};
                q.push({nr, nc, t, d + 1});
            } else if (grid[nr][nc][1].second > d + 1 && grid[nr][nc][0].first != t) {
                grid[nr][nc][1] = {t, d + 1};
                q.push({nr, nc, t, d + 1});
            } else if (grid[nr][nc][1].second == d + 1 &&
                       grid[nr][nc][1].first > t &&
                       grid[nr][nc][0].first != t) {
                grid[nr][nc][1] = {t, d + 1};
                q.push({nr, nc, t, d + 1});
            }
        }
    }

    for (int i = 1; i <= ROWS; i++) {
        for (int j = 1; j <= COLS; j++) {
            printf("%d%s", grid[i][j][0].first, j == COLS ? "\n" :" ");
        }
    }
    for (int i = 1; i <= ROWS; i++) {
        for (int j = 1; j <= COLS; j++) {
            printf("%d%s", grid[i][j][1].first, j == COLS ? "\n" :" ");
        }
    }
    return 0;
}