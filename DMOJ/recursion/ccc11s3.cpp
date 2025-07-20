#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int solve(int m, int x, int y) {
    // printf("at %d %d %d\n", m, x, y);
    if (m == 1) {
        if (y == 0 && (x == 1 || x == 2 || x == 3)) return 1;
        if (y == 1 && x == 2) return 1;
        return 0;
    }

    int rx = x / int(pow(5, m - 1)), ry = y / int(pow(5, m - 1));
    if ((rx == 1 && ry == 1) || (rx == 2 && ry == 2) || (rx == 3 && ry == 1)) {
        return solve(m - 1, x - rx * int(pow(5, m - 1)), y - ry * int(pow(5, m - 1)));
    }
    return solve(1, rx, ry);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        printf("%s\n", solve(a, b, c) ? "crystal" : "empty");
    }
}