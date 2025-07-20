#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, q;
ll nums[200010];

struct node{
    ll value = 0;
    bool flag = false;
    ll flag_value = 0;
    ll l, r;
} tree[800010];
void push(int i) {
    if (tree[i].flag) {
        tree[i * 2].flag = true;
        tree[i * 2].flag_value += tree[i].flag_value;
        tree[i * 2].value += (tree[i].flag_value * (tree[i * 2].r - tree[i * 2].l + 1)) % m;
        tree[i * 2 + 1].flag = true;
        tree[i * 2 + 1].flag_value += tree[i].flag_value;
        tree[i * 2 + 1].value += (tree[i].flag_value * (tree[i * 2 + 1].r - tree[i * 2 + 1].l + 1)) % m;
        tree[i].flag_value = 0;
        tree[i].flag = false;
    }
}
void build(int i, int lt, int rt) {
    tree[i].l = lt;
    tree[i].r = rt;
    // printf("set %d to (%d %d)\n", i, lt, rt);
    if (lt == rt) {
        tree[i].value = nums[lt] % m;
        return;
    }

    int mid = (lt + rt) / 2;
    build(i * 2, lt, mid);
    build(i * 2 + 1, mid + 1, rt);
    tree[i].value = (tree[i * 2].value + tree[i * 2 + 1].value) % m;
}
void update(int i, int lt, int rt, ll v) {
    if (tree[i].l == lt && tree[i].r == rt) {
        tree[i].flag = true;
        tree[i].flag_value += v;
        tree[i].value += (v * (tree[i].r - tree[i].l + 1)) % m;
        return;
    }

    push(i);
    int mid = (tree[i].l + tree[i].r) / 2;
    if (rt <= mid) {
        update(i * 2, lt, rt, v);
    } else if (lt > mid) {
        update(i * 2 + 1, lt, rt, v);
    } else {
        update(i * 2, lt, mid, v);
        update(i * 2 + 1, mid + 1, rt, v);
    }
    tree[i].value = (tree[i * 2].value + tree[i * 2 + 1].value) % m;
}

ll query(int i, int lt, int rt) {
    // printf("i = %d l %d r %d (%d %d)\n", i, lt, rt, tree[i].l, tree[i].r);
    if (tree[i].l == lt && tree[i].r == rt) {
        return tree[i].value % m;
    }
    push(i);
    int mid = (tree[i].l + tree[i].r) / 2;
    // printf("querying %d %d\n");
    if (rt <= mid) {
        return query(i * 2, lt, rt);
    } else if (lt > mid) {
        return query(i * 2 + 1, lt, rt);
    } else {
        return (query(i * 2, lt, mid) + query(i * 2 + 1, mid + 1, rt)) % m;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> m >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    build(1, 1, n);
    for (int i = 0, op, a, b, c; i < q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> c;
            update(1, a, b, c);
        } else {
            cin >> a >> b;
            printf("%lld\n", query(1, a, b) % m);
        }
    }
}
// 10007 10 10
// 0 0 0 0 0 0 0 0 0 0
// 1 1 10 1
// 2 1 10