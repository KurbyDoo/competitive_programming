#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 998244353;
int n;
ll nums[85];
vector<ll> sorted_nums;
set<ll> unique_nums;
unordered_map<ll, ll> ni;
ll dp[85][85][85];
ll total[85];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sorted_nums.push_back(nums[i]);
        unique_nums.insert(nums[i]);
    }
    sort(sorted_nums.begin(), sorted_nums.end());
    for (int i = 0; i < n; i++) {
        ni[sorted_nums[i]] = i + 1;
    }

    set<ll> seen;
    for (int i = 0; i < n; i++) {
        for (ll number: seen) {
            for (int l = n; l > 1; l--) {
                if (l == 2) {
                    dp[2][ni[nums[i]]][ni[number]] = (dp[2][ni[nums[i]]][ni[number]] + dp[1][ni[number]][0]) % mod;
                    // total[2] = (total[2] + dp[1][ni[nums[j]]][0]) % mod;
                    // printf("adding %lld for %d %d\n",dp[1][ni[number]][0], nums[i], number);
                } else if (ni[2 * number - nums[i]] > 0) {
                    dp[l][ni[nums[i]]][ni[number]] = (dp[l][ni[nums[i]]][ni[number]] + dp[l - 1][ni[number]][ni[2 * number - nums[i]]]) % mod;
                    // printf("adding %lld for %d %d l = %d (%d %d)\n", dp[l - 1][ni[nums[j]]][ni[2 * nums[j] - nums[i]]], nums[i], nums[j], l, i, j);
                    // total[l] = (total[l] + dp[l - 1][ni[nums[j]]][ni[2 * nums[j] - nums[i]]]) % mod;
                }
            }
        }
        dp[1][ni[nums[i]]][0] += 1;
        seen.insert(nums[i]);
    }

    // printf("%lld\n", dp[3][ni[3]][ni[2]]);
    // printf("%lld\n", dp[2][ni[2]][ni[1]]);
    // printf("%lld");
    for (int l = 1; l <= n; l++) {
        for (ll a: unique_nums) {
            for (ll b: unique_nums) {
                total[l] = (total[l] + dp[l][ni[a]][ni[b]]) % mod;
                // printf("l = %d %d (%d -> %d)\n", l, dp[l][ni[a]][ni[b]], b, a);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", n);
            continue;
        }
        printf("%lld ", total[i]);
    } return 0;
}

// dp[a][b][l] = num sequences that ended in a -> b of length l
// dp[a][b][l] = dp[b][c - (b - c)][l - 1]
