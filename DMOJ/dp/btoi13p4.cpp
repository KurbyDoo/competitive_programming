// KurbyDoo
// Feb 10th, 2024
// Baltic OI '13 P4 - Brunhilda's Birthday
// https://dmoj.ca/problem/btoi13p4
// UNFINISHED - uses math
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dp[10000010];
int n, q;
int primes[100010];

int search(int pos) {
    if (dp[pos]) return dp[pos];
    if (pos == 0) return 0;

    int best = 999999999;
    for (int i = 0; i < n; i++) {
        if (pos % primes[i] == 0) continue;
        best = min(best, search(pos - (pos % primes[i])) + 1);
    }
    return dp[pos] = best;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> primes[i];
    }

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        int ans = search(a);
        if (ans == 999999999) {
            printf("oo\n");
        } else {
            printf("%d\n", ans);
        }
    }

        return 0;
}