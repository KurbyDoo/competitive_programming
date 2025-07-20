#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int snake_length;
bool hits_apple[15][15];
bool hits_head[15][15];
int smallest_edge 
int vis[15][15];
int real_vis[15][15];
int cur_time;
string grid[15];
int convert_idk(char c) {
    if (c - 'a' < 0) return c - '0' + 1;
    return c - 'a' + 11;
}

void apple_bfs(int ar, int ac) {
    if (ar - 1 < 0 || ar + 1 >= n || ac - 1 < 0 || ac + 1 >= n) return;
    if (hits_apple[ar][ac] || vis[ar][ac] > 0) return;
    hits_apple[ar][ac] = true;
    apple_bfs(ar - 1, ac);
    apple_bfs(ar + 1, ac);
    apple_bfs(ar, ac - 1);
    apple_bfs(ar, ac + 1);
}

void snake_dfs(int ar, int ac) {
    if (ar - 1 < 0 || ar + 1 >= n || ac - 1 < 0 || ac + 1 >= n) return;
    if (hits_head[ar][ac] || vis[ar][ac] > 0) return;
    hits_head[ar][ac] = true;
    snake_dfs(ar - 1, ac);
    snake_dfs(ar + 1, ac);
    snake_dfs(ar, ac - 1);
    snake_dfs(ar, ac + 1);
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A') apple_bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0') snake_dfs(i, j);
        }
    }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         printf("%d ", vis[i][j]);
        //     }
        //     printf("\n");
        // }
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