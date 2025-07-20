/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/466/C
 * Status: Solved
 * Notes:
 *     Original creation date unknown
 *     
 *     
 *     
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nums[500010];
ll suff[500010];
vector<ll> cmp;
ll n, total = 0;
ll solve() {
    if (total % 3 != 0) return 0;
    ll target = total / 3;
    ll temp = 0, ans = 0;
    for (int i = n; i > 0; i--) {
        temp += nums[i];
        suff[i] = temp == target;
        suff[i] += suff[i + 1];
    }
    temp = 0;
    for (int i = 1; i <= n - 2; i++) {
        temp += nums[i];
        ans += temp == target ? suff[i + 2] : 0;
    }
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    printf("%lld\n", solve());
}