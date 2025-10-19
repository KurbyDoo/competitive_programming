#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
bool is_even[200010];
int neighbours[200010];

void dfs(int node, int past, vector<vector<int>>& adj) {
    for (int e : adj[node]) {
        if (e == past) continue;
        is_even[e] = !is_even[node];
        dfs(e, node, adj);
    }
}

void solve() {
    int n, a, b;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) neighbours[i] = 0;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        neighbours[a]++;
        neighbours[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> leaves;
    for (int i = 1; i < n; i++) {
        if (neighbours[i] == 1) leaves.push(i);
    }
    vector<pair<int, int>> ans;
    is_even[1] = false;
    dfs(1, -1, adj);

    bool cur_par = false;
    while (!leaves.empty()) {
        int cur_leaf = leaves.front();
        leaves.pop();
        if (is_even[cur_leaf] == cur_par) {
            ans.push_back({1, 0});
        } else {
            ans.push_back({1, 0});
            ans.push_back({1, 0});
        }
        cur_par = !is_even[cur_leaf];
        ans.push_back({2, cur_leaf});
        for (int e : adj[cur_leaf]) {
            if (e == n) continue;
            neighbours[e]--;
            if (neighbours[e] == 1) leaves.push(e);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%d%s\n", is_even[i], i == n ? "\n" : " ");
    // }
    printf("%d\n", ans.size() - 1);
    for (auto [a, b] : ans) {
        if (a == 1)
            printf("1\n");
        else if (b != ans[ans.size() - 1].second)
            printf("%d %d\n", a, b);
    }
    // printf("\n");
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}