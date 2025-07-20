#include <bits/stdc++.h>
using namespace std;
int n;
int nums[300010];
int target[300010];
int left_pos[300010];
int right_pos[300010];
unordered_map<int, int> last_left;
unordered_map<int, int> last_right;
queue<int> to_check;


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
        if (target[i] == nums[i]) {
            to_check.push(i);
            
        }
    }

    while (!to_check.empty()) {
        int index = to_check.front();
        to_check.pop();
        int remove_num = target[index];
        int l = index - 1, r = index + 1;
        target[index] = 0;
        // for (int i = 1; i <= n; i++) {
        //     printf("%d ", target[i]);
        // }
        // printf("\n");
        while (l > 0 && target[l] == remove_num) {
            target[l] = nums[l];
            to_check.push(l);
            l -= 1;
        }
        while (r <= n && target[r] == remove_num) {
            target[r] = nums[r];
            to_check.push(r);
            r += 1;
        }

    }
    bool works = true;
    for (int i = 1; i <= n; i++) {
        if (target[i] != 0) works = false;
    }

    if (works) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
// 14
// 2 3 4 8 9 2 3 6 8 3 7 1 4 1
// 2 2 3 4 2 2 2 2 3 3 1 4 1 1

// 15
// 2 3 4 8 9 2 3 2 6 8 3 7 1 4 1
// 2 2 3 4 2 3 3 3 2 3 3 1 4 1 1