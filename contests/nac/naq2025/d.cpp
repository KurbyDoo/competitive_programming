#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
queue<tuple<ll, ll, ll>> q;
ll ROWS, COLS, startx, starty, endx, endy;
ll visited[60][60][4];
ll grid[60][60];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> ROWS >> COLS >> startx >> starty >> endx >> endy;
    q.push({startx, starty, 0});

    for (int i = 0; i <= ROWS + 1; i++) {
        for (int j = 0; j <= COLS + 1; j++) {
            // printf("at %d %d\n", i, j);
            if (i == 0 || j == 0 || i == ROWS + 1 || j == COLS + 1) {
                grid[i][j] = 1;
            }
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
            visited[i][j][2] = 0;
            visited[i][j][3] = 0;
        }
    }
    for (int i = 0; i < ROWS; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= COLS; j++) {
            grid[i + 1][j] = (row[j - 1] == '1');
        }
    }

    while (!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();
        // printf("at %d %d %d\n", r, c, d);
        if (r == endx && c == endy) {
            printf("1\n");
            return 0;
        }
        if (visited[r][c][d]) {
            printf("0\n");
            return 0;
        }
        visited[r][c][d] = 1;
        vector<ll> dx = {0, 1, 0, -1};
        vector<ll> dy = {1, 0, -1, 0};
        int left = grid[r + dx[(d + 3) % 4]][c + dy[(d + 3) % 4]];
        int fwd = grid[r + dx[d % 4]][c + dy[d % 4]];
        if (!left) {
            q.push({r + dx[(d + 3) % 4], c + dy[(d + 3) % 4], (d + 3) % 4});
        } else if (!fwd) {
            q.push({r + dx[d % 4], c + dy[d % 4], d});
        } else {
            q.push({r, c, (d + 1) % 4});
        }
    }
    return 0;
}