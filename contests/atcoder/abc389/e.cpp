// broken idk why maybe overflow
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;
ll n, m, pi;
ll prices[200010];
ll used[200010];
ll solve(ll end_price) {
    ll cur_cost = 0;
    for (int i = 0; i < n; i++) {
        ll x = (end_price + prices[i]) / (2ULL * prices[i]);
        // printf("x = %lld pi = %lld\n", x, prices[i]);
        if (x > 1000000000ULL) return m + 1ULL;
        cur_cost += x * x * prices[i];
    }
    return cur_cost;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pi;
        prices[i] = pi;
    }

    ll l = 0ULL, r = m;
    while (l < r) {
        ll mid = (l + r + 1ULL) / 2ULL;
        ll temp = solve(mid);
        // printf("cost for end price of %lld is %lld\n", mid, temp);
        if (temp > m) {
            r = mid - 1ULL;
        } else {
            l = mid;
        }
    }
    ll ans = 0;
    ll curr = 0;
    for (int i = 0; i < n; i++) {
        // if (l < prices[i]) continue;
        ll x = (l + prices[i]) / (2ULL * prices[i]);
        used[i] = x;
        ans += x;
        curr += x * x * prices[i];
        // printf("used %lld of %lld next = %lld\n", x, prices[i], (2 * used[i] + 1) * prices[i]);
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({(2ULL * used[i] + 1ULL) * prices[i], i});
    }

    while (pq.top().first + curr <= m) {
        ll a = pq.top().first;
        ll b = pq.top().second;
        pq.pop();
        ans += 1;
        curr += a;
        used[b] += 1;
        pq.push({(2ULL * used[b] + 1ULL) * prices[b], b});
    }

    printf("%llu\n", ans);

    return 0;
}