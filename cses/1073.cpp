#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int nums[200010];
int bit[200010];
int n;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }    

    for (int i = 1; i <= n; i++) {
        if (dp.empty() || dp.back() <= nums[i]) {
            dp.push_back(nums[i]);
        } else {
            *upper_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
    }
    printf("%d\n", dp.size());
    
}
