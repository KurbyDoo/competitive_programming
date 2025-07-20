#include <bits/stdc++.h>
using namespace std;
int n;
int nums[300010];
int target[300010];
int left_needed[300010];
int right_needed[300010];
bool works = true;
unordered_map<int, int> last_left;
unordered_map<int, int> last_right;
vector<array<int, 3>> operations;


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

    for (int i = 1; i <= n; i++) {
        last_left[nums[i]] = i;
        left_needed[i] = last_left[target[i]];
    }
    for (int i = n; i > 0; i--) {
        last_right[nums[i]] = i;
        right_needed[i] = last_right[target[i]];
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", left_needed[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", right_needed[i]);
    // }
    // printf("\n");

    int l = 1, r = n;
    int left_swipe = 0, right_swipe = 0;
    int rr = 0;
    while (l <= n && works) {
        printf("at %d leftneed = %d rightneed= %d rihgt = %d left = %d\n", l, left_needed[l], right_needed[l], right_swipe, left_swipe);
        if (nums[l] == target[l]) {
            l += 1;
        } else if (left_needed[l] != 0 && left_swipe <= left_needed[l] && l >= right_swipe) {
            left_swipe = left_needed[l];
            l += 1;
            operations.push_back({1, left_swipe, l});
        } else if (right_needed != 0  && (right_swipe <= right_needed[l] || l >= right_swipe)) {
            right_swipe = right_needed[l];
            rr = l;
            operations.push_back({0, l, right_needed[l]});
            l += 1;
        } else {
            // printf("breaks at %d\n", l);
            works = false;
        }

    }

    if (works) {
        printf("YES\n");
        printf("%d\n", operations.size());
        for (int i = 0; i < operations.size(); i++) {
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

// 11
// 1 1 2 3 2 1 1 2 3 2 1
// 2 2 3 3 3 2 3 2 1 1 1

// 6
// 3 1 5 6 1 2
// 3 1 2 1 2 2