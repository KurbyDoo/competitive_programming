#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, q, ai, bi;
int nums[200010];
bool bad[200010];
int errors = 0;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        if (nums[(i + n - 1) % n] > nums[i] || nums[(i + 1) % n] < nums[i]) {
            bad[i] = true;
            errors += 1;
            pq.push({nums[i], i});
            // printf("bad at %d %d %d %d\n", i, nums[(i + n - 1) % n], nums[i], nums[(i + 1) % n]);
        }
    }

    while (q--) {
        cin >> ai >> bi;
        ai--;
        if (bad[ai]) errors -= 1;
        if (bad[(ai + n - 1) % n]) errors -= 1;
        if (bad[(ai + 1) % n]) errors -= 1;
        bad[ai] = false;
        bad[(ai + n - 1) % n] = false;
        bad[(ai + 1) % n] = false;
        nums[ai] = bi;
        pq.push({nums[ai], n - ai});
        for (int i = ai - 1 + n; i <= ai + 1 + n; i++) {
            if (nums[(i - 1) % n] > nums[i % n] || nums[(i + 1) % n] < nums[i % n]) {
                bad[i % n] = true;
                pq.push({nums[i % n], i % n});
                errors += 1;
                // printf("u bad at %d: %d %d %d\n", i % n, nums[(i - 1) % n], nums[i % n], nums[(i + 1) % n]);
            }

        }

        while (!pq.empty()) {
            auto [a, b] = pq.top();
            if (nums[b] != a) pq.pop();
            else break;
        }

        if (errors > 2) {
            printf("-1\n");
        } else if (errors == 0) {
            printf("0\n");
        } else {
            auto [a, b] = pq.top();
            // printf("%d %d\n", a, b);
            int ans = min(b, n - b);
            printf("%d\n", ans);
        }
        
    }
    
    return 0;
}