#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[25000010];
ll n, m, q, a;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i * j] += 1;
            arr[n * m + 1 - (n - i + 1) * (m - j + 1) + 1] -= 1;
        }
    }
    for (int i = 1; i <= n * m; i++) {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < q; i++) {
        cin >> a;
        printf("%lld\n", arr[a]);
    }
    return 0;
}
