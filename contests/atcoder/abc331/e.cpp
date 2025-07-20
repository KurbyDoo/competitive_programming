#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, l;
unordered_map<ll, unordered_map<ll, bool>> bad;
vector<pair<ll, ll>> sorted_main;
ll mains[100010];
vector<pair<ll, ll>> sides;
ll ans = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        cin >> mains[i + 1];
    }
    for (int i = 0, a; i < m; i++) {
        cin >> a;
        sides.push_back({a, i + 1});
    }

    for (int i = 0, a, b; i < l; i++) {
        cin >> a >> b;
        bad[a][b] = true;
    }
    sort(sides.begin(), sides.end(), greater<pair<ll, ll>>());

    for (int i = 1; i <= n; i++) {
        ll cur_price = mains[i];
        for (auto [price, index]: sides) {
            if (bad[i][index]) continue;
            cur_price += price;
            break;
        }
        ans = max(ans, cur_price);
    }
    printf("%lld\n", ans);
}