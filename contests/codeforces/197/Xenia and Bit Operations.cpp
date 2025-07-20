// https://codeforces.com/problemset/problem/339/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nums[200010];
ll tree[800010];
int n, m;
ll p, v;
void build(int i, int l, int r, int depth) {
    if (depth == 0) {
        tree[i] = nums[l];
        return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid, depth - 1);
    build(i * 2 + 1, mid + 1, r, depth - 1);
    if (depth % 2) tree[i] = tree[i * 2] | tree[i * 2 + 1];
    else tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
}
void update(int i, int l, int r, int depth, int loc, ll val) {
    if (depth == 0) {
        tree[i] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (loc <= mid) update(i * 2, l, mid, depth - 1, loc, val);
    else update(i * 2 + 1, mid + 1, r, depth - 1, loc, val);
    if (depth % 2) tree[i] = tree[i * 2] | tree[i * 2 + 1];
    else tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= (1 << n); i++) {
        cin >> nums[i];
    }
    build(1, 1, 1 << n, n);
    for (int i = 0; i < m; i++) {
        cin >> p >> v;
        update(1, 1, 1 << n, n, p, v);
        printf("%lld\n", tree[1]);
    }
    return 0;
}