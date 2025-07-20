#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, k, needed;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k;
        needed = k + sqrtl(k);
        if (needed - ll(sqrtl(needed)) < k) { // before: sqrt(needed)
            needed += 1;
        }
        printf("%lld\n", needed);
    }
}