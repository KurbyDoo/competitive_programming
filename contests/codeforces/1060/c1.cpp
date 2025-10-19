#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
bool not_prime[200010];
vector<ll> primes;
ll n, nums[200010], cost[200010];
vector<ll> factors[200010];

void compute_factors(int a) {
    if (factors[a].size() != 0) return;
    if (!not_prime[a]) {
        factors[a].push_back(a);
        return;
    }
    int num = a;
    for (int p : primes) {
        if (p > num) return;
        if (num % p != 0) continue;
        factors[a].push_back(p);
        while (num % p == 0) num /= p;
    }
}

int solve() {
    cin >> n;
    int num_non_ones = 0;
    vector<int> non_ones;
    vector<bool> found1 = vector<bool>(200010);
    vector<bool> found2 = vector<bool>(200010);
    vector<bool> inq = vector<bool>(200010);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (nums[i] != 1) {
            num_non_ones++;
            if (inq[nums[i]]) continue;
            non_ones.push_back(nums[i]);
            inq[nums[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    if (non_ones.size() != num_non_ones) return 0;  // found dupe
    if (non_ones.size() > primes.size()) return 0;  // to many

    int ans = 2;

    for (int num : non_ones) {
        int num1 = num, num2 = num + 1;
        // printf("checking %d = %d\n", i, nums[i]);
        compute_factors(num1);
        compute_factors(num2);
        for (int f : factors[num1]) {
            if (found1[f]) return 0;
            if (found2[f]) ans = 1;
        }
        for (int f : factors[num2]) {
            if (found1[f]) ans = 1;
        }
        for (int f : factors[num1]) {
            found1[f] = true;
        }
        for (int f : factors[num2]) {
            found2[f] = true;
        }
        // printf("ans = %d\n", ans);
    }

    if (found1[2] && num_non_ones != n) ans = 1;  // one exists and even
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    not_prime[0] = true;
    not_prime[1] = true;
    for (int i = 2; i <= 200000; i++) {
        if (not_prime[i]) continue;
        primes.push_back(i);
        for (int j = i * 2; j <= 200000; j += i) {
            not_prime[j] = true;
        }
    }
    // printf("total primes = %d\n", primes.size());
    int t;
    cin >> t;
    while (t--) {
        printf("%d\n", solve());
    }

    return 0;
}