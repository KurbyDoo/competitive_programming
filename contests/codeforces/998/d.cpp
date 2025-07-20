#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;

void solve() {
    int n;
    int nums[200010];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] <= nums[i + 1]) {
            nums[i + 1] -= nums[i];
            nums[i] = 0;
        } else {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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
