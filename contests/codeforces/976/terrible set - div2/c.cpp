#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, a, b, c, d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> b >> c >> d;
        int max_length = 100;
        a = 0;
        for (int i = 0; i <= max_length; i++) {
            // printf("%d %d %d\n", (b >> i) & 1, (c >> i) & 1, (d >> i) & 1);
            if (!((b >> i) & 1) && ((c >> i) & 1)) continue;
            else if (((b >> i) & 1) && !((c >> i) & 1)) a |= (1LL << i); // before: (1 << i)
            else if (!((b >> i) & 1) && !((c >> i) & 1)) a |= d & (1LL << i);
            else if (((b >> i) & 1) && ((c >> i) & 1)) a |= (d & (1LL << i)) ^ (1LL << i);
        }
        
        // printf("%lld\n", a);
        if ((a | b) - (a & c) != d) {
            printf("-1\n");
        } else {
            printf("%lld\n", a);
        }
    }
}