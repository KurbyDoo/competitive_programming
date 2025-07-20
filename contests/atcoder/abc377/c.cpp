#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll n, m, a, b;
set<pii> captured;
void inb(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= n) {
        captured.insert({x, y});
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        inb(a, b);
        inb(a + 2, b + 1);
        inb(a + 1, b + 2);
        inb(a - 1, b + 2);
        inb(a - 2, b + 1);
        inb(a - 2, b - 1);
        inb(a - 1, b - 2);
        inb(a + 1, b - 2);
        inb(a + 2, b - 1);
    }

    printf("%lld\n", n * n - captured.size());
    return 0;
}