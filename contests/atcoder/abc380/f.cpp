#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dp[4200][4200][2];
ll cards[15];
vector<ll> smaller[15];
int n, m, l;
int solve(int a, int b, bool is_taka) {
    if (dp[a][b][is_taka]) return dp[a][b][is_taka];
    // printf("%d %d\n", a, b);
    if (is_taka) {
        for (int i = 0; i < n + m + l; i++) {
            if (!((a >> i) & 1)) continue;
            for (int c: smaller[i]) {
                if (((a | b) >> c) & 1) continue;
                if (solve((a ^ (1 << i)) | (1 << c), b, false) == 1) {
                    return dp[a][b][is_taka] = 1;
                }
            }
            if (solve(a ^ (1 << i), b, false) == 1) {
                return dp[a][b][is_taka] = 1;
            }
        }
        return dp[a][b][is_taka] = 2;
    } else {
        for (int i = 0; i < n + m + l; i++) {
            if (!((b >> i) & 1)) continue;
            for (int c: smaller[i]) {
                if (((a | b) >> c) & 1) continue;
                if (solve(a, (b ^ (1 << i)) | (1 << c), true) == 2) {
                    return dp[a][b][is_taka] = 2;
                }
            }
            if (solve(a, b ^ (1 << i), true) == 2) {
                return dp[a][b][is_taka] = 2;
            }
        }
        return dp[a][b][is_taka] = 1;
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> l;
    int taka = 0, table = 0, aoki = 0;
    for (int i = 0; i < n + m + l; i++) {
        cin >> cards[i];
        if (i < n) {
            taka |= (1 << i);
        } else if (i < n + m) {
            aoki |= (1 << i);
        } else {
            table |= (1 << i);
        }
    }
    for (int i = 0; i < n + m + l; i++) {
        for (int j = 0; j < n + m + l; j++) {
            if (i == j) continue;
            if (cards[j] < cards[i])
                smaller[i].push_back(j);
        }
    }
    solve(taka, aoki, true);
    printf("%s\n", dp[taka][aoki][true] == 1 ? "Takahashi" : "Aoki");
    return 0;
}