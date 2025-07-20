#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[(1 << 16) + 10], adj[20][20];
int n;
ll solve(int state) {
    if (state == (1 << n) - 1) return 0;
    if (dp[state]) return dp[state];

    ll best = 0;
    for (int i = 1; i <= n; i++) {
        if (state >> (i - 1) & 1) continue;
        for (int j = i + 1; j <= n; j++) {
            if (state >> (j - 1) & 1) continue;
            best = max(best, solve(state | (1 << (j - 1)) | (1 << (i - 1))) + adj[i][j]);
        }
    }
    return dp[state] = best;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    printf("%lld\n", solve(0));

    return 0;
}