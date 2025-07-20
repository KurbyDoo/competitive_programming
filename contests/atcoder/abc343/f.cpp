#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a, b, c;
int n, q;
int ai;
pair<pii, pii> tree[800010];


pair<pii, pii> get_min(pair<pii, pii> a, pair<pii, pii> b) {
  pii biggest;
  pii smaller;
  if (a.first.first > b.first.first) {
    biggest = {a.first.first, a.first.second};
    if (b.first.first > a.second.first) {
      smaller = {b.first.first, b.first.second};
    } else if (b.first.first < a.second.first) {
      smaller = {a.second.first, a.second.second};
    } else {
      smaller = {a.second.first, a.second.second + b.first.second};
    }
  } else if (a.first.first < b.first.first) {
    biggest = {b.first.first, b.first.second};
    if (a.first.first > b.second.first) {
      smaller = {a.first.first, a.first.second};
    } else if (a.first.first < b.second.first) {
      smaller = {b.second.first, b.second.second};
    } else {
      smaller = {b.second.first, b.second.second + a.first.second};
    }
  } else {
    biggest = {a.first.first, a.first.second + b.first.second};
    if (a.second.first > b.second.first) {
      smaller = {a.second.first, a.second.second};
    } else if (a.second.first < b.second.first) {
      smaller = {b.second.first, b.second.second};
    } else {
      smaller = {a.second.first, a.second.second + b.second.second};
    }
  }
  return {biggest, smaller};
}

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = {{0, 0}, {-1, 0}};
    return;
  }

  int mid = (l + r) / 2;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  tree[i] = get_min(tree[i * 2], tree[i * 2 + 1]);
}

void update(int i, int l, int r, int loc, int v) {
  if (l == loc && r == loc) {
    tree[i] = {{v, 1}, {0, 0}};
    return;
  }

  int mid = (l + r) / 2;
  if (loc <= mid) {
    update(i * 2, l, mid, loc, v);
  } else {
    update(i * 2 + 1, mid + 1, r, loc, v);
  }
  tree[i] = get_min(tree[i * 2], tree[i * 2 + 1]);
}

pair<pii, pii> query(int i, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return tree[i];
  }

  int mid = (l + r) / 2;
  if (qr <= mid) {
    return query(i * 2, l, mid, ql, qr);
  } else if (ql > mid) {
    return query(i * 2 + 1, mid + 1, r, ql, qr);
  } else {
    return get_min(query(i * 2, l, mid, ql, mid), query(i * 2 + 1, mid + 1, r, mid + 1, qr));
  }
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
      cin >> ai;
      update(1, 1, n, i, ai);
    }

    for (int i = 0; i < q; i++) {
      cin >> a >> b >> c;
      if (a == 1) {
        update(1, 1, n, b, c);
      } else {
        pair<pii, pii> ans = query(1, 1, n, b, c);
        // printf("%d %d %d %d\n", ans.first.first, ans.first.second, ans.second.first, ans.second.second);
        printf("%d\n", ans.second.second);
      }
    }
      return 0;
}