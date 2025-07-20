#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, xi, yi;
ll px[200010];
ll py[200010];
ll x_avg = 0;
ll y_avg = 0;

bool simulate(ll side_length) {
    ll upper_y = y_avg + side_length
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> px[i] >> py[i];
        x_avg += px[i];
        y_avg += py[i];
    }

    x_avg = x_avg / n;
    y_avg = y_avg / n;

    ll l = 0, r = 1000000000;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        
        if (simulate(mid)) r = mid;
        else l = mid + 1;
    }

}