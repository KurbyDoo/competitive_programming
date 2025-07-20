#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll n, k;
ll total_sum = 0;
ll totals[1000010];
ll nums[1000010];
ll ks[1000010];
ll left_most[1000010];
ll psa[1000010];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i + 1];
        psa[i + 1] = psa[i] + nums[i + 1];
    }
    for (int i = 0; i < k; i++) {
        cin >> ks[i + 1];
        left_most[i + 1] = n + 1;
    }

    for (int i = n; i > 0; i--) {
        // printf("checking %d (%d) left = %d\n", nums[i], i, left_most[nums[i]]);
        if (left_most[nums[i]] >= i) {
            // printf("%d was not included\n", nums[i]);
            totals[nums[i]] += psa[i] - psa[max((ll)0, i - ks[nums[i]] - 1)];
            left_most[nums[i]] = max((ll)0, i - ks[nums[i]] - 1);
            // printf("new left = %d\n", left_most[nums[i]]);
        } else {
            // printf("%d was included\n", nums[i]);
            totals[nums[i]] += psa[left_most[nums[i]]] - psa[max((ll)0, left_most[nums[i]] - ks[nums[i]] - 1)];
            left_most[nums[i]] = max((ll)0, left_most[nums[i]] - ks[nums[i]] - 1);
            // printf("new left = %d\n", left_most[nums[i]]);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%lld\n", psa[n] - totals[i]);
    }
    return 0;
}
// 8 4
// 4 4 4 4 4 2 1 1
// 2 1 1 1

// 7 4
// 4 3 2 1 2 1 1
// 4 2 1 1