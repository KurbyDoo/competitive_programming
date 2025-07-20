#include <bits/stdc++.h>
using namespace std;
int n;
int grid[2010][2010];
int rows[2010];
int cols[2010];
int ans = 0;
vector<string> out;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (grid[i][1] == 1) {
            rows[i] = 1;
            ans += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((grid[1][i] + rows[1]) % 2 == 1) {
            cols[i] = 1;
            ans += 1;
        }

    }

    bool works = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // printf("%d ", (grid[i][j] + rows[i] + cols[j]) % 2);
            if ((grid[i][j] + rows[i] + cols[j]) % 2 != 0) works = false;
            if (!works) break;
        }
        if (!works) break;
    }

    if (works) {
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) {
            if (rows[i] == 1) printf("R %d\n", i);
        }
        for (int i = 1; i <= n; i++) {
            if (cols[i] == 1) printf("C %d\n", i);
        }
    } else {
        printf("-1\n");
    }
}