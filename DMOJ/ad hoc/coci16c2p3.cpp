#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, ans = 0;
int nums[1000010];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    int l = 0, ls = 0, r = n + 1, rs = 0;
    while (l < r) {
        if (ls == rs) {
            l += 1;
            r -= 1;
            ls += nums[l];
            rs += nums[r];
        } else if (ls < rs) {
            l += 1;
            ls += nums[l];
            ans += 1;
        } else if (rs < ls) {
            r -= 1;
            rs += nums[r];
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
// 10
// 1 2 3 4 4 6 7 8 9 10
// 3 3 4 5 6 7 8 9 10
// 6 4 5 6 7 8 9 10
// 10 5 6 7 8 9 10
// 10 11 7 8 9 10
// 10 11 7 17 10
// 10 18 17 10
// 10 35 10