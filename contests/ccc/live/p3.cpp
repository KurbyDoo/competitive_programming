#include <bits/stdc++.h>
using namespace std;
int n;
int nums[300010];
int target[300010];
unordered_map<int, int> last_left;
unordered_map<int, int> last_right;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> target[i];
    }

    int l = 1, r = n;
    int left_swipe = 0, right_swipe = n + 1;
    bool right_possible = true;
    bool left_possible = true;
    vector<array<int, 3>> operations;
    while (l <= r && (right_possible || left_possible)) {
        printf("at %d %d\n", l, r);
        if (nums[l] == target[l]) {
            last_left[nums[l]] = l;
            l += 1;
        } else {
            printf("ll of %d is %d ls = %d\n", target[l], last_left[target[l]], left_swipe);
            if (last_left[target[l]] >= left_swipe) {
                left_swipe = last_left[target[l]];
                last_left[nums[l]] = l;
                l += 1;
                operations.push_back({1, left_swipe, l});
            } else {
                left_possible = false;
            }
        }

        if (nums[r] == target[r]) {
            last_right[nums[r]] = r;
            r -= 1;
        } else {
            if (last_right[target[r]] >= right_swipe) {
                right_swipe = last_right[target[r]];
                last_right[nums[r]] = r;
                r -= 1;
                operations.push_back({0, r, right_swipe});
            } else {
                right_possible = false;
            }
        }
    }
    if (left_possible || right_possible) {
        printf("YES\n");
        printf("%d\n", operations.size());
        for (int i = operations.size() - 1; i >= 0; i--) {
            printf("%s %d %d\n", operations[i].at(0) == 0 ? "L" : "R", operations[i].at(1), operations[i].at(2));
        }
    } else {
        printf("NO\n");
    }
}
// 14
// 2 3 4 8 9 2 3 6 8 3 7 1 4 1
// 2 2 3 4 2 2 2 2 3 3 1 4 1 1

// 7
// 1 1 1 2 3 2 1
// 1 3 2 1 1 1 1

// 10
// 1 2 3 2 1 1 2 3 2 1
// 2 3 3 3 2 3 2 1 1 1