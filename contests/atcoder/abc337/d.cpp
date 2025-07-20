#include <bits/stdc++.h>
using namespace std;
string grid[200010];
int h, w, k;
int ans = 9999999;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> h >> w >> k;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    for (int y = 0; y < h; y++) {
        int x_count = 0, dot_count = 0;
        for (int i = 0; i < min(k - 1, w); i++) {
            if (grid[y].at(i) == 'x') x_count++;
            else if (grid[y].at(i) == '.') dot_count++;
        }

        for (int i = 0; i + k - 1 < w; i++) {
            if (grid[y].at(i + k - 1) == 'x') x_count++;
            else if (grid[y].at(i + k - 1) == '.') dot_count++;

            if (x_count == 0) ans = min(ans, dot_count);
            // printf("%d at (%d, %d)\n", ans, i, y);

            if (grid[y].at(i) == 'x') x_count--;
            else if (grid[y].at(i) == '.') dot_count--;
        }

    }

    for (int x = 0; x < w; x++) {
        int x_count = 0, dot_count = 0;
        for (int i = 0; i < min(k - 1, h); i++) {
            if (grid[i].at(x) == 'x') x_count++;
            else if (grid[i].at(x) == '.') dot_count++;
        }

        for (int i = 0; i + k - 1 < h; i++) {
            if (grid[i + k - 1].at(x) == 'x') x_count++;
            else if (grid[i + k - 1].at(x) == '.') dot_count++;

            if (x_count == 0) ans = min(ans, dot_count);
            // printf("%d at (%d, %d)\n", ans, x, i);

            if (grid[i].at(x) == 'x') x_count--;
            else if (grid[i].at(x) == '.') dot_count--;
        }
    }
    printf("%d\n", ans == 9999999 ? -1 : ans);
    return 0;
}