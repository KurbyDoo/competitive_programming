/**
 * Author: KurbyDoo
 * Creation Date: Jul 28, 2025
 * Problem Link: https://atcoder.jp/contests/abc415/tasks/abc415_f
 * Problem Name: F - Max Combo
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
    ll max_val = 0;
    ll left = 0;
    ll right = 0;
} _tree[2000010];

int n, q, ttype, ai, bi;
string s;
char S[500010], ci;

node merge(node& left, node& right, ll mid, ll l, ll r) {
    node new_node;
    new_node.max_val = max(left.max_val, right.max_val);
    new_node.left = left.left;
    new_node.right = right.right;
    if (S[mid] == S[mid + 1]) {
        new_node.max_val = max(new_node.max_val, left.right + right.left);
        if (left.left == mid - l + 1) {
            new_node.left = left.left + right.left;
        }
        if (right.right == r - mid) {
            new_node.right = right.right + left.right;
        }
    }
    // printf("left = %d %d %d\n", left.left, left.max_val, left.right);
    // printf("right = %d %d %d\n", right.left, right.max_val, right.right);
    // printf("got %d %d %d at %d %d %d\n", new_node.left, new_node.max_val,
    //        new_node.right, l, mid, r);
    return new_node;
}

void build(ll i, ll l, ll r) {
    if (l == r) {
        _tree[i] = {1, 1, 1};
        return;
    }
    ll mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);

    _tree[i] = merge(_tree[i * 2], _tree[i * 2 + 1], mid, l, r);
}

void update(ll i, ll l, ll r, ll pos, char c) {
    if (l == pos && pos == r) {
        S[l] = c;
        return;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid)
        update(i * 2, l, mid, pos, c);
    else
        update(i * 2 + 1, mid + 1, r, pos, c);
    _tree[i] = merge(_tree[i * 2], _tree[i * 2 + 1], mid, l, r);
}

node query(ll i, ll l, ll r, ll ql, ll qr) {
    // printf("at %d %d %d %d %d\n", i, l, r, ql, qr);
    if (l == ql && r == qr) {
        return _tree[i];
    }
    ll mid = (l + r) / 2;
    if (qr <= mid)
        return query(i * 2, l, mid, ql, qr);
    else if (mid < ql)
        return query(i * 2 + 1, mid + 1, r, ql, qr);

    node left = query(i * 2, l, mid, ql, mid);
    node right = query(i * 2 + 1, mid + 1, r, mid + 1, qr);
    return merge(left, right, mid, ql, qr);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        S[i] = s[i - 1];
    }

    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        cin >> ttype;
        if (ttype == 1) {
            cin >> ai >> ci;
            update(1, 1, n, ai, ci);
        } else {
            cin >> ai >> bi;
            printf("%lld\n", query(1, 1, n, ai, bi).max_val);
        }
    }
    return 0;
}