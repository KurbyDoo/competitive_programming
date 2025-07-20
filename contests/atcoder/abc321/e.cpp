# include <bits/stdc++.h>

using std::cin;
typedef long long ll;
int t;
ll n, x, k;

ll bfs(ll node, ll dist, ll past) {
    if (node > n || node == 0) return 0;
    if (dist == k) return 1;
    ll total = 0;
    if (node / 2 != past) total += bfs(node / 2, dist + 1, node);
    if (node * 2 != past) total += bfs(node * 2, dist + 1, node);
    if (node * 2 + 1 != past) total += bfs(node * 2 + 1, dist + 1, node);
    return total;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n >> x >> k;
        printf("%llu\n", bfs(x, 0, 0));
    }

    return 0;
}