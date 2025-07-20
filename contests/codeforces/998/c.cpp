#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;

    for (int i = 0, ai; i < n; i++) {
        cin >> ai;
        nums.push_back(ai);
    }
    int ans = 0;
    sort(nums.begin(), nums.end());
    int l = 0, r = n - 1;
    while (l < r) {
        // printf("%d %d\n", nums[l], nums[r]);
        if (nums[l] + nums[r] == k) {
            ans += 1;
            l++;
            r--;
        } else if (nums[l] + nums[r] < k) {
            l++;
        } else {
            r--;
        }
    }
    printf("%d\n", ans);
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

