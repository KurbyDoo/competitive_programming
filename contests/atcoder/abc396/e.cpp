#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
unordered_map<ll, vector<pll>> graph;
ll xi, yi, zi, n, m;
bool visited[200010];
ll value[200010];
vector<ll> cur;
bool dfs(int node, int past) {
    cur.push_back(node);
    for (auto [e, c]: graph[node]) {
        if (visited[e]) {
            if (value[e] != (value[node] ^ c)) {
                // printf("contradiction %d %d %d %d %d\n", e, node, c, value[e], value[node]);
                // printf("%d = %d (%d) (%d)\n", value[e], value[node] ^ c, value[e] != value[node] ^ c, value[e] != (value[node] ^ c));
                return false;
            }
        } else {
            value[e] = value[node] ^ c;
            visited[e] = true;
            if (!dfs(e, node)) return false;
        }
    }
    return true;
}

bool solve(ll start) {
    cur.clear();
    visited[start] = true;
    if (!dfs(start, -1)) return false;
    for (ll k = 0; k <= 30; k++) {
        int cnt = 0;
        for (auto x: cur) {
            if (value[x] & (1LL << k)) cnt++;
        }

        if (cnt > cur.size() - cnt) {
            for (auto x: cur) {
                value[x] = value[x] ^ (1LL << k);
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> xi >> yi >> zi;
        graph[xi].push_back({yi, zi});
        graph[yi].push_back({xi, zi});

    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        if (!solve(i)) {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 1; i < n; i++) {
        printf("%lld ", value[i]);
    }
    printf("%lld\n", value[n]);
    return 0;
}