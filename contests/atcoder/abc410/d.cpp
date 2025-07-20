#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m;
ll ai, bi, wi;
vector<pll> adj[1100][1100];
bool visited[1100][1100];

void dfs(int n, int v) {
    for (pll p : adj[n][v]) {
        if (visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;
        dfs(p.first, p.second);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi >> wi;
        for (int j = 0; j < (1 << 10); j++) {
            adj[ai][j].push_back({bi, j ^ wi});
        }
    }

    dfs(1, 0);
    for (int i = 0; i < (1 << 10); i++) {
        if (visited[n][i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", -1);
    return 0;
}