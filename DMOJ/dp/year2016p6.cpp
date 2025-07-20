#include <bits/stdc++.h>
using namespace std;
int dp[2][1 << 21];
int weights[22];
int L, R, w;
int solve(int b, int last) {
    if (dp[last == -1 ? 0 : 1][b]) return dp[last == -1 ? 0 : 1][b];
    if (b == (1 << (L + R)) - 1) return 0;

    int ls = 0, rs = 0;
    for (int i = 0; i < L + R; i++) {
        if (b >> i & 1) {
            if (i < L) ls += weights[i];
            else rs += weights[i];
        }
    }
    if (abs(ls - rs) > w) return 100000;

    int moves = 100000;
    for (int i = 0; i < L; i++)
    {
        if (!(b >> i & 1)) {
            moves = min(solve(b | (1 << i), -1) + (last == 1), moves);
        }
    }
    for (int i = L; i < L + R; i++) {
        if (!(b >> i & 1)) {
            moves = min(solve(b | (1 << i), 1) + (last == -1), moves);
        }
    }
    dp[last == -1 ? 0 : 1][b] = moves;
    // printf("moves for %d is %d\n", b, moves);
    return dp[last == -1 ? 0 : 1][b];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> L >> R >> w;
    for (int i = 0; i < L + R; i++) {
        cin >> weights[i];
    }
    printf("%d\n", solve(0, 0) + 1);
}