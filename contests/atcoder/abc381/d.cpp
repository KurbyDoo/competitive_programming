#include <bits/stdc++.h>
using namespace std;
int nums[200010];
int n, ans = 0;
void saw(int i, unordered_map<int, int> &l1, unordered_map<int, int> &l2) {
    l2[nums[i]] = l1[nums[i]];
    l1[nums[i]] = i;
}

void do_thing(int start) {
    int l = start, r = start + 1;
    unordered_map<int, int> last1;
    unordered_map<int, int> last2;
    saw(l, last1, last2);
    saw(r, last1, last2);
    while (r <= n) {
        // printf("%d %d\n", l, r);
        if (nums[r] != nums[r - 1]) {
            // printf("not equal\n");
            r += 2;
            l = r - 1;
            saw(l, last1, last2);
            saw(r, last1, last2);
        } else {
            ans = max(r - l + 1, ans);
            r += 2;
            if (r > n) break;
            // printf("saw %d : %d %d\n", r - 1, last1[nums[r - 1]], last2[nums[r - 1]]);
            while (l + 2 < r && last2[nums[r - 1]] > l) {
                l += 2;
            }
            saw(r - 1, last1, last2);

            // printf("saw %d : %d %d\n", r, last1[nums[r]], last2[nums[r]]);
            while (l + 2 < r && last2[nums[r]] > l) {
                l += 2;
            }
            saw(r, last1, last2);
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    do_thing(1);
    do_thing(2);
    printf("%d\n", ans);
    return 0;
}