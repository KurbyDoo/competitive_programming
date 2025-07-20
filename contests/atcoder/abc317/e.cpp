#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int h, w;
bool danger[2010][2010];
string grid[2010];
queue<pii> q;
void vision(int row, int col) {
    char square = grid[row][col];
    if (square == '.' || square == 'S' || square == 'G') return;
    danger[row][col] = true;
    if (square == '<') {
        for (int i = col - 1; i >= 0; i--) {
            if (grid[row][i] != '.') break;
            danger[row][i] = true;
        }
    } else if (square == '>') {
        for (int i = col + 1; i < w; i++) {
            if (grid[row][i] != '.') break;
            danger[row][i] = true;
        }
    } else if (square == '^') {
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] != '.') break;
            danger[i][col] = true;
        }
    } else if (square == 'v') {
        for (int i = row + 1; i < h; i++) {
            if (grid[i][col] != '.') break;
            danger[i][col] = true;
        }
    } 
}

void solve(int start_r, int start_c) {
    queue<array<int, 3>> q;
    q.push({start_r, start_c, 0});
    danger[start_r][start_c] = true;
    while (!q.empty()) {
        auto [r, c, dist] = q.front();
        // printf("at %d %d\n", r, c);
        if (grid[r][c] == 'G') {
            printf("%d\n", dist);
            return;
        }
        q.pop();
        if (0 <= r - 1 && !danger[r - 1][c]) {
            q.push({r - 1, c, dist + 1});
            danger[r - 1][c] = true;
        }
        if (r + 1 < h && !danger[r + 1][c]) {
            q.push({r + 1, c, dist + 1});
            danger[r + 1][c] = true;
        }
        if (0 <= c - 1 && !danger[r][c - 1]) {
            q.push({r, c - 1, dist + 1});
            danger[r][c - 1] = true;
        }
        if (c + 1 < w && !danger[r][c + 1]) {
            q.push({r, c + 1, dist + 1});
            danger[r][c + 1] = true;
        }
    }
    printf("-1\n");
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            vision(r, c);
            if (grid[r][c] == '#') danger[r][c] = true;
        }
    }

    // for (int r = 0; r < h; r++) {
    //     for (int c = 0; c < w; c++) {
    //         printf("%d ", danger[r][c] ? 1 : 0);
    //     }
    //     printf("\n");
    // }

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (grid[r][c] == 'S') solve(r, c);
        }
    }
    return 0;
}