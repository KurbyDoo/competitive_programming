/**
 * Author: KurbyDoo
 * Creation Date: Jul 28, 2025
 * Problem Link: https://atcoder.jp/contests/abc415/tasks/abc415_d
 * Problem Name: D - Get Many Stickers
 * Status: Solved
 * Notes:
 *     Operation 1 does not matter
 *     Use op with lowest diff until below threshold
 *
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, ai, bi;
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ai >> bi;
        pq.push({ai - bi, ai});
    }

    ll ans = 0;

    while (!pq.empty()) {
        auto [cur_diff, cur_req] = pq.top();
        pq.pop();
        if (n >= cur_req) {
            ll rem = (n - cur_req) % cur_diff;
            ans += (n - cur_req) / cur_diff;
            n = cur_req + rem - cur_diff;
            ans += 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}