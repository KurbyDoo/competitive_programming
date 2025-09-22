/**
 * Author: KurbyDoo
 * Creation Date: Sep 22, 2025
 * Problem Link: https://atcoder.jp/contests/arc202/tasks/arc202_a
 * Problem Name: A - Merge and Increment
 * Status: Unsolved
 * Notes:
 *
 *
 *
 *
 **/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
struct node {
    ll l, r, value;
};

node nodes[200010];
ll nums[200010];
ll sz[200010];
priority_queue<pll, vector<pll>, greater<pll>> pq;

ll t, n, ai, ans;

ll find(ll a) {
    if (nums[a] == a) {
        return a;
    }
    return nums[a] = find(nums[a]);
}

bool join(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (nodes[a].value != nodes[b].value) return false;
    // printf("merging a = (%d %d %d) b = (%d %d %d)\n", nodes[a].l,
    //        nodes[a].value, nodes[a].r, nodes[b].l, nodes[b].value, nodes[b].r);
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    nums[b] = a;
    nodes[a].value += 1;
    nodes[a].l = min(nodes[a].l, nodes[b].l);
    nodes[a].r = max(nodes[a].r, nodes[b].r);
    // printf("merging a = (%d %d %d)\n", nodes[a].l, nodes[a].value, nodes[a].r);
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ai;
            nodes[i].l = i;
            nodes[i].r = i;
            nodes[i].value = ai;
            nums[i] = i;
            sz[i] = 1;
            pq.push({ai, i});
        }

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            idx = find(idx);
            node nn = nodes[idx];
            pq.pop();

            if (sz[idx] == n) break;
            // printf("val idx = %d %d\n", val, idx);
            if (nn.value != val) {
                continue;
            }

            if (nn.l - 1 > 0 && join(nn.l, nn.l - 1)) {
                pq.push({nodes[find(nn.l)].value, idx});
            } else if (nn.r + 1 <= n && join(nn.r, nn.r + 1)) {
                pq.push({nodes[find(nn.r)].value, idx});
            } else {
                ll smallest = 999999999999;
                if (nn.l - 1 > 0) {
                    smallest = min(smallest, nodes[find(nn.l - 1)].value);
                }
                if (nn.r + 1 <= n) {
                    smallest = min(smallest, nodes[find(nn.r + 1)].value);
                }
                ll diff = smallest - nodes[idx].value;
                nodes[idx].value += diff;
                pq.push({nodes[idx].value, idx});
                ans += diff;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}