#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 400010;
ll tree[MM * 4];
ll nums[MM];
ll pre[MM * 4];
ll suf[MM * 4];
ll n, q, a, b;

void build(int i, int l, int r) {
    if (l == r) {
        nums[l] = 0;
        tree[i] = 1;
        pre[i] = 1;
        suf[i] = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    tree[i] = (r - l + 1);
    pre[i] = (r - l + 1);
    suf[i] = (r - l + 1);
}

void update(int i, int l, int r, int p, int v) {
    if (l == p && r == p) {
        nums[l] = v;
        tree[i] = 1;
        suf[i] = 1;
        pre[i] = 1;
        return;
    }

    int mid = (l + r) / 2;
    if (p <= mid) update(i * 2, l, mid, p, v);
    if (p > mid) update(i * 2 + 1, mid + 1, r, p, v);
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    pre[i] = pre[i * 2];
    suf[i] = suf[i * 2 + 1];
    if (tree[i * 2] == mid - l  + 1 && nums[mid] <= nums[mid + 1]) {
        pre[i] = pre[i * 2] + pre[i * 2 + 1];
    }
    if (tree[i * 2 + 1] == r - mid && nums[mid] <= nums[mid + 1]) {
        suf[i] = suf[i * 2 + 1] + suf[i * 2];
    }
    if (nums[mid] <= nums[mid + 1]) {
        tree[i] = max(tree[i], suf[i * 2] + pre[i * 2 + 1]);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        update(1, 1, n, i, a);
        // for (int i = 1; i <= n; i++) {
        //     printf("%lld ", nums[i]);
        // }
        // printf("\n");
        // printf("new = %lld\n", tree[1]);
    }

    printf("%lld\n", tree[1]);
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        update(1, 1, n, a, b);
        printf("%lld\n", tree[1]);
    }
    return 0;
}