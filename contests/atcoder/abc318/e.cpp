#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, ai;
ll last[300010], amount[300010];
ll added[300010];
ll ans = 0;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        if (amount[ai] > 0) {
            added[ai] += (i - last[ai] - 1) * (amount[ai]);
            ans += added[ai];
        }
        last[ai] = i;
        amount[ai]++;
    }
    printf("%lld\n", ans);

    return 0;
}