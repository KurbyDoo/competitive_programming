#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n;
ll a[110], b[110], p[110], q[110], X;

bool get_cost(ll amnt) {
    ll total_cost = 0;
    for (int i = 0; i < n; i++) {
        ll tms = amnt / (a[i] * b[i]);
        total_cost += tms * min(p[i] * b[i], q[i] * a[i]);
        ll rem = amnt % (a[i] * b[i]);
        ll cur_min = 2e9l;
        for (int ai = 0; ai < b[i]; ai++) {
            cur_min = 
        }
    }

}

void solve() {
    ll l = 0;
    ll r = 2e9l;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        ll cst = get_cost(mid);
        if (cst <= X) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("lld\n", get_cost(l));
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> X;
    for (int i = 0; i < i; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    solve();
    return 0;
}