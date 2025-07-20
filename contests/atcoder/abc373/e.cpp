#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, remaining_votes;
ll votes[200010];
ll psa[200010];
ll ans[200010];
vector<pair<ll, ll>> sorted_votes;
ll ranking[200010];

void solve(ll cur_votes, ll cur_pos, ll cur_rank) {
    // printf("solving %d %d %d\n", cur_votes, cur_pos, cur_rank);
    // printf("%d - %d < %d = %d\n", n, cur_rank, m, n - cur_rank < m);
    if (n - cur_rank >= m) { // not in top
        ll l = 0, r = remaining_votes + 1;
        while (l < r) {
            // printf("%d %d\n", l, r);
            ll mid = (l + r) / 2;
            // printf("mid =%d | %d > %d?\n", mid, (psa[n] - psa[n - m] + (remaining_votes - mid)) / m, (cur_votes + mid));
            if ((psa[n] - psa[n - m] + (remaining_votes - mid)) / m > (cur_votes + mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        ans[cur_pos] = r == remaining_votes + 1 ? -1 : r;
        // printf("found %d for %d\n", ans[cur_pos], cur_pos);
    } else { // in top
        ll l = 0, r = remaining_votes + 1;
        ll above = n - cur_rank;
        ll below = m - above;
        // printf("av = %d bl = %d\n", above, below);
        while (l < r) {
            // printf("%d %d\n", l, r);
            ll mid = (l + r) / 2;
            // printf("mid = %d | %d > %d?\n", mid, (psa[n] - psa[n - above] + psa[cur_rank - 1] - psa[cur_rank - below - 1] + (remaining_votes - mid)) / m, (cur_votes + mid));
            if ((psa[cur_rank - below - 1] + (remaining_votes - mid)) / below > cur_votes + mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        ans[cur_pos] = r == remaining_votes + 1 ? -1 : r;
        // printf("found %d for %d\n", ans[cur_pos], cur_pos);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> votes[i];
        sorted_votes.push_back({votes[i], i});
    }

    sort(sorted_votes.begin(), sorted_votes.end());

    for (int i = 1; i <= n; i++) {
        psa[i] += psa[i - 1] + sorted_votes[i - 1].first;
    }
    remaining_votes = k - psa[n];

    for (int i = 0; i < n; i++) {
        ranking[sorted_votes[i].first] = i + 1;

    }
    for (int i = 0; i < n; i++) {
        solve(sorted_votes[i].first, sorted_votes[i].second, ranking[sorted_votes[i].first]);

    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    
}