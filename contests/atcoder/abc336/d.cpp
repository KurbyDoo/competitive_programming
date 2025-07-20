#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> up;
vector<int> down;
int nums[200010];
int n, ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i <= n; i++) {
        int big = 0, small = 0;
        if (up.empty() || up.back() < nums[i]) {
            up.push_back(nums[i]);
            big = up.size();
        } else {
            int l = 0, r = up.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (up.at(mid) < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                big = l + 1;
                up[l] = nums[i];
            }
        }

        if (down.empty() || down.back() > nums[i]) {
            down.push_back(nums[i]);
            small = down.size();
        } else {
            int l = 0, r = down.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (down.at(mid) > nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                small = l + 1;
                down[l] = nums[i];
            }
        }

        ans = max(ans, min(big, small));
        ans = max(ans, int(up.size() + 1) / 2);
        ans = max(ans, int(down.size() + 1) / 2);
    }
    printf("%d\n", ans);
}