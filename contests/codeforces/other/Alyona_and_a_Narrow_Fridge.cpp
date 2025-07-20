/*
 * Author: KurbyDoo
 * Creation Date: Jul 19, 2025
 * Problem Link: https://codeforces.com/problemset/problem/1119/B
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
ll n, h;
ll nums[1010];
bool solve(int k) {
    vector<ll> bottles;
    for (int i = 1; i <= k; i++) {
        bottles.push_back(nums[i]);
    }
    sort(bottles.begin(), bottles.end());
    ll height = 0;
    for (int i = bottles.size() - 1; i >= 0; i -= 2) {
        height += bottles[i];
    }
    return height <= h;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> h;
    int l = 0, r = n;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (solve(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", l);
    return 0;
}