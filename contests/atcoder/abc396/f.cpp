#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bit[200010];
ll n, m, inv = 0, nums[200010], lft[200010], rht[200010], cnt[200010];
vector<ll> cycle[200010];
ll query(int pos) {
    ll v = 0;
    for (; pos > 0; pos -= pos & -pos) {
        v += bit[pos];
    }
    return v;
}

void update(int pos) {
    for (; pos <= 200000; pos += pos&-pos) {
        bit[pos] += 1;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> nums[i];
        inv += (i - 1) - query(nums[i] + 1);
        lft[i] = (query(nums[i] + 1) - query(nums[i]));
        cycle[m - nums[i] - 1].push_back(i);
        update(nums[i] + 1);
        
    }

    for (int i = n; i > 0; i--) {
        rht[i] = cnt[nums[i]];
        cnt[nums[i]] += 1;
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("L = %d R = %d\n", lft[i], rht[i]);
    // }

    for (int i = 0; i < m; i++) {
        printf("%lld\n", inv);
        for (ll a: cycle[i]) {
            inv -= (n - a) - rht[a];
            inv += (a - 1) - lft[a];
        }
    }
}