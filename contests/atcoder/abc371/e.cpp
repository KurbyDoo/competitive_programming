#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll nums[200010];
ll last_location[200010];
ll ans, row_sum;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      last_location[nums[i]] = n;
    }

    ans = 0;
    row_sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      row_sum += last_location[nums[i]] - i;
      last_location[nums[i]] = i;
      ans += row_sum;
    }

    printf("%lld\n", ans);
    return 0;
}