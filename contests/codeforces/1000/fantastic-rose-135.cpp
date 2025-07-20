#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;
int n, ui, vi;

void solve() {
    vector<int> adj[200010];
    int nb[200010];
    fill(begin(nb), end(nb), 0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
        nb[vi] += 1;
        nb[ui] += 1;
    }

    if (n <= 2) {
        printf("0\n");
        return;
    }

    int ans = 0;
    pii big = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (nb[i] > big.first) big = {nb[i], i};
    }
    ans += big.first;
    printf("%d %d\n", big.first, big.second);
    for (int e: adj[big.second]) {
        nb[e] -= 1;
    }
    nb[big.second] = 0;
    big = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (nb[i] > big.first) big = {nb[i], i};
    }
    ans += big.first - 1;
    printf("%d\n", ans);
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        // printf("hi\n");
        // newFunc();
        solve();
    }

    return 0;
}