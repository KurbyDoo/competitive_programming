#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, ni;
int ans[500010];
int bit[500010];
int nums[500010];
void update(int loc, int val) {
    for (; loc <= n; loc += loc & -loc) {
        // printf("u at %d\n", loc);
        bit[loc] = max(val, bit[loc]);
    }
}
int query(int loc) {
    int a = 0;
    for (; loc > 0; loc -= loc & -loc) {
        // printf("query %d %d\n", loc, bit[loc]);
        a = max(bit[loc], a);
    }
    return a;
}
void solve() {
    priority_queue<pii> pq;
    // unordered_map<int, int> pos;
    cin >> n;
    int biggest_num = n;
    for (int i = 0; i < n; i++) {
        cin >> ni;
        nums[i + 1] = ni;
        pq.push({ni, i + 1});
        bit[i + 1] = 0;
        ans[i + 1] = 0;
        // pos[ni] = i;
    }

    while (!pq.empty()) {
        auto [num, idx] = pq.top();
        pq.pop();
        int res = max(query(biggest_num), num);
        update(idx, res);
        // printf("res = %d big = %d\n", res, biggest_num);
        // printf("q = %d\n", query(biggest_num));
        ans[idx] = res;
        while (biggest_num > 0 && ans[biggest_num] != 0) {
            // printf("%d\n", biggest_num);
            biggest_num--;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
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