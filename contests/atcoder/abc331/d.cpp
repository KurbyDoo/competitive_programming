#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, q;
ll a, b, c, d;
string row;
int grid[2010][2010];
ll query_rect(int x1, int y1, int x2, int y2) {
    ll ans = 0;
    ans += grid[y2][x2];
    if (x1 != 0) ans -= grid[y2][x1 - 1];
    if (y1 != 0) ans -= grid[y1 - 1][x2];
    if (x1 != 0 && y1 != 0) ans += grid[y1 - 1][x1 - 1];
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int r = 0; r < n; r++) {
        cin >> row;
        for (int c = 0; c < n; c++) {
            grid[r][c] = row[c] == 'B' ? 1 : 0;
            grid[r + n][c] = grid[r][c];
            grid[r][c + n] = grid[r][c];
            grid[r + n][c + n] = grid[r][c];
        }
    }

    for (int r = 0; r <= n * 2; r++) {
        for (int c = 0; c <= n * 2; c++) {
            if (r == 0 && c == 0) continue;
            else if (r == 0) grid[r][c] += grid[r][c - 1];
            else if (c == 0) grid[r][c] += grid[r - 1][c];
            else grid[r][c] += grid[r - 1][c] + grid[r][c - 1] - grid[r - 1][c - 1];
        }
    }

    // for (int r = 0; r <= n * 2; r++) {
    //     for (int c = 0; c <= n * 2; c++) {
    //         printf("%3d ", grid[r][c]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < q; i++) {
        cin >> b >> a >> d >> c;
        ll width = (c - a) / n;
        ll height = (d - b) / n;
        ll x1 = a % n;
        ll y1 = b % n;
        ll x2 = x1 + (c - a) % n;
        ll y2 = y1 + (d - b) % n;
        // printf("new coords = %d %d %d %d\n", x1, y1, x2, y2);
        ll total = 0;
        total += (width * height) * query_rect(0, 0, n - 1, n - 1);
        // printf("center %lld\n", (width * height) * query_rect(0, 0, n - 1, n - 1));
        total += (width) * query_rect(0, y1, n - 1, y2);
        // printf("top + bottom %lld\n", (width) * query_rect(0, y1, n - 1, y2));
        total += (height) * query_rect(x1, 0, x2, n - 1);
        // printf("left + right %lld\n", (height) * query_rect(x1, 0, x2, n - 1));
        total += query_rect(x1, y1, x2, y2);
        // printf("corners %lld\n", query_rect(x1, y1, x2, y2));

        printf("%lld\n", total);
    }
    
}