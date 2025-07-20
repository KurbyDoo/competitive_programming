#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int nums[200010];
set<int> all_nums;
unordered_map<int, int> c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i <= 200001; i++) {
        all_nums.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (c[nums[i]] == 0 && all_nums.find(nums[i]) != all_nums.end()) {
            all_nums.erase(nums[i]);
        }
        c[nums[i]] += 1;
        
    }

    for (int i = 0, ik, xk; i < q; i++) {
        cin >> ik >> xk;
        c[nums[ik]] -= 1;
        if (c[nums[ik]] == 0 && nums[ik] <= 200001) {
            all_nums.insert(nums[ik]);
        }

        nums[ik] = xk;
        if (c[xk] == 0 && all_nums.find(xk) != all_nums.end()) {
            all_nums.erase(xk);
        }
        c[xk] += 1;
        
        printf("%d\n", *all_nums.begin());
    }

    return 0;
}