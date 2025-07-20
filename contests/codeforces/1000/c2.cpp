#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;

void solve() {
    int n, ui, vi;
    cin >> n;
    vector<int> adj[n + 1];
    vector<int> neigh(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
        neigh[vi] += 1;
        neigh[ui] += 1;
    }
    neigh[0] = -1;
    if (n <= 2) {
        printf("0\n");
        return;
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%d = %d\n", i, neigh[i]);
    // }

        int ans = 0;
    pii big = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (neigh[i] > neigh[big.first]) {
            int big2 = 0;
            for (int e: adj[i]) {
                if (neigh[e] == neigh[i]) {
                    big2 += 1;
                }
            }
            big = {i, big2};
        } else if (neigh[i] == neigh[big.first]) {
            int big2 = 0;
            for (int e : adj[i]) {
                if (neigh[e] == neigh[i]) {
                    big2 += 1;
                }
            }
            if (big2 < big.second) big = {i, big2};
        }
    }
    ans += neigh[big.first];
    // printf("%d %d\n", big.first, big.second);
    for (int e: adj[big.first]) {
        neigh[e] -= 1;
    }
    neigh[big.first] = 0;
    big = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (neigh[i] > neigh[big.first]) big = {i, i};
    }
    ans += neigh[big.first] - 1;
    printf("%d\n", ans);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
    }

    return 0;
}

// 11
// 2 1
// 3 1
// 4 1
// 1 5
// 5 6
// 5 7
// 5 8
// 8 9
// 8 10
// 8 11