#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
void solve() {
    ll n, cnt = 0, mm = 999999999999999999999999999999, mx = -1;
    ll total = 0;
    stack<pair<ll, ll>> stk;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> total;
        cnt = 1;
        // push elements to rigth most until it is > a_i
        // if a_i is small, you can fill gap using past to make average smaller
        // => max smaller
        while (stk.size() && stk.top().first * cnt >= total) {
            total += stk.top().first * stk.top().second;
            cnt += stk.top().second;
            stk.pop();
        }
        // floor
        stk.push({total / cnt, cnt - total % cnt});
        if (total % cnt != 0) { // ceil
            stk.push({total / cnt + 1, total % cnt});
        }
    }

    mx = stk.top().first;
    while (stk.size() > 1) stk.pop();
    mm = stk.top().first;
    printf("%lld\n", mx - mm);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}