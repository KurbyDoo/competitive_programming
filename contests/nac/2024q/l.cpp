#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int snake_length;
int vis[15][15];
int real_vis[15][15];
int cur_time;
string grid[15];
int convert_idk(char c) {
    if (c - 'a' < 0) return c - '0' + 1;
    return c - 'a' + 11;
}

void solve(int start_r, int start_c) {
    queue<array<int, 3>> q;
    q.push({cur_time, start_r, start_c});
    while (!q.empty())
    {
        auto [t, r, c] = q.front();
        real_vis[r][c] = true;
        // printf("at %d %d %d\n", r, c, t);
        if (grid[r][c] == 'A') {
            printf("1\n");
            return;
        }
        q.pop();
        if (r - 1 >= 0 && !real_vis[r - 1][c] && t - vis[r - 1][c] >= 0) {
            q.push({t + 1, r - 1, c});
        }
        if (r + 1 < n && !real_vis[r + 1][c] && t - vis[r + 1][c] >= 0) {
            q.push({t + 1, r + 1, c});
        }
        if (c - 1 >= 0 && !real_vis[r][c - 1] && t - vis[r][c - 1] >= 0) {
            q.push({t + 1, r, c - 1});
        }
        if (c + 1 >= 0 && !real_vis[r][c + 1] && t - vis[r][c + 1] >= 0) {
            q.push({t + 1, r, c + 1});
        }
    }
    printf("0\n");
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    snake_length = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.') snake_length++;
        }
    }
    snake_length -= 1;
    cur_time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            if (grid[i][j] == 'A') continue;
            vis[i][j] = (snake_length - convert_idk(grid[i][j]));
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", vis[i][j]);
    //     }
    //     printf("\n");
    // }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') {
                solve(i, j);
            }
        }
    }
    return 0;
}

// 9 2
// A.
// 78
// 69
// 5a
// 4b
// 3c
// 2d
// 1e
// 0f

// 10 2
// A.
// ..
// 67
// 58
// 49
// 3a
// 2b
// 1c
// 0d
// fe

// 10 2
// A.
// ..
// 56
// 47
// 38
// 29
// 1a
// 0b
// dc
// ef

// 10 10
// 0.........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// ..........
// .........A

// 10 10
// ..........
// ..........
// ..43210...
// ..5edc....
// ..6fAb....
// ..789a....
// ..........
// ..........
// ..........
// ..........

// 10 10
// ..........
// ..........
// ..........
// ..........
// ..........
// 45678.....
// 32..9.....
// .1cba.....
// .0dA......
// ..ef......