// Author: KurbyDoo
// Created: 2025-07-07 20:21:31
// Problem Name
// https://dmoj.ca/problem/cco18p1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

string S, T;
ll n, A[1010], B[1010];
ll dp[1010][1010];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    cin >> S;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cin >> T;
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (S[i - 1] == 'W' && T[j - 1] == 'L' && A[i] > B[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + A[i] + B[j]);
            }
            if (S[i - 1] == 'L' && T[j - 1] == 'W' && A[i] < B[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + A[i] + B[j]);
            }
        }
    }
    printf("%lld\n", dp[n][n]);
    return 0;
}