#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
ll total_sum = 0;
set<int> debt;
unordered_map<int, int> counts;
int totals[1000010];
int nums[1000010];
int ks[1000010];
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
    }

    int counter = 0;
    for (int i = n; i > 0; i--) {
        if (counts[nums[i]] == 0) {
            debt.insert(nums[i]);
        }
        counts[nums[i]] += ks[nums[i]] + 1;

        queue<int> to_remove;
        for (int a: debt) {
            totals[a] += nums[i];
            counts[a] -= 1;
            if (counts[a] == 0) {
                to_remove.push(a);
            }
        }
        while (!to_remove.empty()) {
            int a = to_remove.front();
            to_remove.pop();
            debt.erase(a);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%lld\n", psa[n] - totals[i]);
    }

        return 0;
}
// 7 4
// 4 3 2 1 1 1 2
// 1 1 1 1

// 7 4
// 4 3 2 1 2 1 1
// 1 1 1 1