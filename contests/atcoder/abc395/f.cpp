#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll N, X, total_cost;
ll upper[200010], lower[200010];
bool grinded[200010];
priority_queue<pll, vector<pll>, greater<pll>> pq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> upper[i] >> lower[i];
        pq.push({upper[i], i});
    }


    while (!pq.empty()) {
        ll cur_size, cur_pos, diff;
        tie(cur_size, cur_pos) = pq.top();
        pq.pop();
        if (grinded[cur_pos]) continue;
        grinded[cur_pos] = true;
        if (cur_pos - 1 > 0) {
            diff = upper[cur_pos - 1] - upper[cur_pos];
            if (diff > X) {
                total_cost += diff - X;
                upper[cur_pos - 1] -= diff - X;
                pq.push({upper[cur_pos - 1], cur_pos - 1});
            }
        }
        if (cur_pos + 1 <= N) {
            diff = upper[cur_pos + 1] - upper[cur_pos];
            if (diff > X) {
                total_cost += diff - X;
                upper[cur_pos + 1] -= diff - X;
                pq.push({upper[cur_pos + 1], cur_pos + 1});
            }
        }
    }

    ll H = upper[1] + lower[1];
    for (int i = 1; i <= N; i++) {
        H = min(upper[i] + lower[i], H);
    }

    for (int i = 1; i <= N; i++) {
        total_cost += (upper[i] + lower[i]) - H;
    }
    printf("%lld\n", total_cost);
}