#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, ans, ai, bi;
ll bit[400010];
ll nums[400010];
ll pv[400010];
unordered_map<ll, ll> qq;
priority_queue<pll, vector<pll>, greater<pll>> queries;

void update(ll pos, ll val) {
    for (; pos <= 2 * n; pos += pos & -pos) {
        bit[pos] += val;
    }
}

ll query(ll pos) {
    ll val = 0;
    for (; pos > 0; pos -= pos & -pos) {
        val += bit[pos];
    }
    return val;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> ai >> bi;
        if (qq[ai]) {
            queries.push({i, qq[ai]});
        } else {
            qq[ai] = i;
        }
        nums[i] = bi;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (pv[nums[i]]) {
            update(pv[nums[i]], -1);

        } 
        update(i, 1);
        pv[nums[i]] = i;

        while (!queries.empty() && queries.top().first <= i) {
            ll l = queries.top().second;
            ll r = queries.top().first;
            // printf("q = %lld %lld val = %d\n", l, r, query(r) - query(l - 1));
            ans += (r - l + 1) - (query(r) - query(l - 1));
            queries.pop();
        }
    }
    printf("%lld\n", ans);
}