#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll t, n, c, ui, vi, gold[200010], dp[2][200010];
vector<ll> graph[200010];

void search(ll node, ll past) {
    dp[1][node] = gold[node];
    dp[0][node] = 0;
    int neigh = 0;
    for (int e: graph[node]) {
        if (e == past) continue;
        // neigh += 1;
        search(e, node);
        dp[1][node] += max(dp[1][e] - 2 * c, dp[0][e]);
        dp[0][node] += max(dp[1][e], dp[0][e]);
    }
    dp[1][node] -= c * neigh;
}

void solve() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> gold[i];
        dp[0][i] = 0;
        dp[1][i] = 0;
        graph[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> ui >> vi;
        graph[ui].push_back(vi);
        graph[vi].push_back(ui);
    }

    search(1, -1);
    printf("%lld\n", max(dp[0][1], dp[1][1]));
    // for (int i = 1; i <= n; i++) {
    //     printf("%lld %lld\n", dp[0][i], dp[1][i]);
    // }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
}