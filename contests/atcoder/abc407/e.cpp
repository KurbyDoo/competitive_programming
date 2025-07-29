/**
 * Author: KurbyDoo
 * Creation Date: Jul 20, 2025
 * Problem Link: https://atcoder.jp/contests/abc407/tasks/abc407_e
 * Problem Name: E - Most Valuable Parentheses
 * Status: Unsolved / Read Editorial
 * Notes:
 * 	A new way to construct () strings
 * 	ive never seen before
 * 	
 * 	
**/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll t;

void solve() {
    ll n, ans = 0;
    priority_queue<ll> pq;
    cin >> n;
    vector<ll> nums(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> nums[i];
    }

    for (int k = 1; k <= n; k++) {
        if (k == 1) pq.push(nums[k]);
        else {
            pq.push(nums[k * 2 - 2]);
            pq.push(nums[k * 2 - 1]);
        }
        ans += pq.top();
        pq.pop();
    }

    printf("%lld\n", ans);
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}