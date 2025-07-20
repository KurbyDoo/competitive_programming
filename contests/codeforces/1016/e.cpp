#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll t, n, k;
ll nums[200010];
unordered_map<ll, ll> found;
ll cur_par = 1;
bool works(ll mid) {
    ll cur_sum = 0;
    ll goal = mid * (mid - 1) / 2;
    if (mid == 0) goal = 0;
    cur_par += 1;
    ll start_par = cur_par; // 1 done 2 done 3 done 4 end - start >= k
    for (int i = 0; i < n; i++) {
        // printf("at %d=%d p=%d cs=%d goal=%d found?=%d\n", i, nums[i], cur_par, cur_sum, goal, found[nums[i]]);
        if (nums[i] >= mid) continue;
        if (found[nums[i]] < cur_par) {
            // printf("found new = %d\n", nums[i]);
            cur_sum += nums[i];
            found[nums[i]] = cur_par;
        }

        if (found[0] == cur_par && cur_sum == goal) {
            cur_par += 1;
            cur_sum = 0;
        }
    }
    // printf("made %lld complete partitions with m = %lld\n", cur_par - start_par, mid);
    return cur_par - start_par >= k;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll l = 0, r = (n / k) + 1;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (works(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%lld\n", l);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}