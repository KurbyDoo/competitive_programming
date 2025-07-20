#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
unordered_map<ll, vector<ll>> graph;
ll dp[1000010];
int past[1000010];
int children[1000010]
int n;
ll solve(int n) {
    if (dp[n]) return dp[n];
    ll total = 1;
    ll child = 0;
    for (ll e: graph[n]) {
        total = ((total % mod) * (solve(e) % mod)) % mod;
        total = (total * counter) % mod;
        counter++;
    }
    printf("total for %d is %lld\n", n, total);
    return dp[n] = total;
}
int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> past[i];
    }
    for (int i = 1; i <= n; i++) {
        graph[past[i]].push_back(i);
    }

    printf("%lld\n", solve(0));
}