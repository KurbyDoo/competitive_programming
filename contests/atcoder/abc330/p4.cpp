#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string grid[2010];
int row_count[2010];
int col_count[2010];
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (grid[y][x] == 'o') {
                row_count[y] += 1;
                col_count[x] += 1;
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (grid[y][x] == 'o') {
                ans += (row_count[y] - 1) * (col_count[x] - 1);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}