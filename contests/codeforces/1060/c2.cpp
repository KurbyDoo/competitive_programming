#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
bool not_prime[400010];
ll n, nums[200010], cost[200010], found[200010];
vector<ll> factors[200010];
ll cur_iter = 0;

ll solve() {
    cur_iter++;
    cin >> n;
    ll min1 = 9999999999, min2 = 9999999999;
    int smallidx = -1;
    vector<ll> unique_fact;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        if (cost[i] < min1) {
            smallidx = i;
            min2 = min1;
            min1 = cost[i];
        } else if (cost[i] < min2) {
            min2 = cost[i];
        }
    }

    ll ans = min1 + min2;

    for (int i = 1; i <= n; i++) {
        for (int f : factors[nums[i]]) {
            if (found[f] == cur_iter) return 0;
            found[f] = cur_iter;
            if (i != smallidx) unique_fact.push_back(f);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == smallidx) continue;
        int num = nums[i];
        for (int f : factors[num]) {
            found[f] = 0;
        }
        for (int f : factors[num + 1]) {
            if (found[f] == cur_iter) ans = min(ans, cost[i]);
        }
        for (int f : factors[num]) {
            found[f] = cur_iter;
        }
    }

    for (int f : unique_fact) {
        int total = f - (nums[smallidx] % f);
        ans = min(ans, total * min1);
    }

    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 2; i <= 200000; i++) {
        if (factors[i].size()) continue;
        factors[i].push_back(i);
        for (int j = i * 2; j <= 200000; j += i) {
            factors[j].push_back(i);
        }
    }
    // printf("total primes = %d\n", primes.size());
    int t;
    cin >> t;
    while (t--) {
        printf("%lld\n", solve());
    }

    return 0;
}