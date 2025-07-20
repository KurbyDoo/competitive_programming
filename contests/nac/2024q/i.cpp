#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
string grid[40];
bool lit[40][40];
bool bulb[40][40];
bool block[40][40];
bool valid = true;
bool search_light(int r, int c, int want) {
    int ans = 0;
    if (r - 1 >= 0) ans += grid[r - 1][c] == '?' ? 1 : 0;
    if (r + 1 < n) ans += grid[r + 1][c] == '?' ? 1 : 0;
    if (c - 1 >= 0) ans += grid[r][c - 1] == '?' ? 1 : 0;
    if (c + 1 < n) ans += grid[r][c + 1] == '?' ? 1 : 0;
    // printf("ans = %d expected %d at %d %d\n", ans, want, r, c);
    return ans == want;
}

bool spread_light(int r, int c) {
    for (int i = r - 1; i >= 0; i--) {
        if (block[i][c]) break;
        if (bulb[i][c]) return false;
        lit[i][c] = true;
    } 
    for (int i = r + 1; i < n; i++) {
        if (block[i][c]) break;
        if (bulb[i][c]) return false;

        lit[i][c] = true;
    } 
    for (int i = c - 1; i >= 0; i--) {
        if (block[r][i]) break;
        if (bulb[r][i]) return false;

        lit[r][i] = true;
    } 
    for (int i = c + 1; i < n; i++) {
        if (block[r][i]) break;
        if (bulb[r][i]) return false;
        lit[r][i] = true;
    }
    return true;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'X') block[i][j] = true;
            else if (grid[i][j] == '.') continue;
            else if (grid[i][j] == '?') bulb[i][j] = true;
            else {
                block[i][j] = true;
                if (!search_light(i, j, int(grid[i][j]) - int('0'))) {
                    printf("0\n");
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '?') {
                if (!spread_light(i, j)) {
                    // printf("%d %d\n", i, j);
                    printf("0\n");
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lit[i][j] || block[i][j] || bulb[i][j]) continue;
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}