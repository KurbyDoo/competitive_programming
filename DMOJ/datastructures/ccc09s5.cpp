#include <bits/stdc++.h>
using namespace std;
int grid[30010][1010];
int n, m, k;
int a, b, c, d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c >> d;
        for (int x = max(1, a - c); x <= min(n, a + c); x++) {
            // x^2 + y^2 = r^2
            // y = +-sqrt(r^2 - x^2)
            int dx = a - x;
            int y1 = max(1, b - int(sqrt(c * c - dx * dx)));
            int y2 = min(m, b + int(sqrt(c * c - dx * dx)));
            // printf("%d %d - %d\n", x, y1, y2);
            grid[y1][x] += d;
            grid[y2 + 1][x] -= d;
        }
    }
    int big = 0;
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            grid[y][x] += grid[y - 1][x];
            if (grid[y][x] > big) {
                ans = 1;
                big = grid[y][x];
            } else if (grid[y][x] == big) {
                ans += 1;
            }
            // printf("%d ", grid[y][x]);
        }
        // printf("\n");
    }
    printf("%d\n", big);
    printf("%d\n", ans);
    return 0;
}
// 3
// 5
// 1
// 5 1 1 5
// 1 3 2 5
// 3 1 2 7