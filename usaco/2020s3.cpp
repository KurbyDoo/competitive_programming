#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> adj[100010];
ll n, m, a, b, c, big;
int dfs_cnt = 1;
int vis[100010];
int nums[100010];
void dfs(ll node, ll min_length) {
    vis[node] = dfs_cnt;
    for (auto [e, d]: adj[node]) {
        if (vis[e] == vis[node]) continue;
        if (d < min_length) continue;
        dfs(e, min_length);
    }
}
bool check(int thing) {
    int st = dfs_cnt;
    for (int i = 1; i <= n; i++) {
        dfs_cnt++;
        if (vis[i] <= st) dfs(i, thing); 
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] != vis[nums[i]]) return false;
    }
    return true;
}
int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        big = max(big, c + 1);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    ll l = 0, r = big;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << (l == big ? -1 : l) << endl;
    return 0;
}