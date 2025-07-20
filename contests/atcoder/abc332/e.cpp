#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double n, d;
double average = 0;
double weights[20];
double dp[100000][20];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
        average += weights[i];
    }
    average = average / d;

    dp[0][0] = 0;
    for (int k = 0; k < d; k++) {
        for (int mask = 0; mask <= 1 << n; mask++) {
            
            dp[mask][k + 1] = min(dp[mask][k]
        }
    }
}