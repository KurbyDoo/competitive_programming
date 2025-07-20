#include <bits/stdc++.h>
using namespace std;
struct node
{
    bool flag = false;
    int v;
} tree[4000010];

void push(int i, int tl, int tr)
{
    if (!tree[i].flag) return;
    // printf("pushing from %d\n", i);
    tree[i].flag = false;
    int mid = (tl + tr) / 2;
    tree[i * 2].flag = !tree[i * 2].flag;
    tree[i * 2].v = (mid - tl + 1) - tree[i * 2].v;
    tree[i * 2 + 1].flag = !tree[i * 2 + 1].flag;
    tree[i * 2 + 1].v = (tr - (mid + 1) + 1) - tree[i * 2 + 1].v;
}
void build(int i, int tl, int tr)
{
    if (tl == tr) {
        tree[i].v = 1;
        return;
    }

    int mid = (tl + tr) / 2;
    build(i * 2, tl, mid);
    build(i * 2 + 1, mid + 1, tr);
    tree[i].v = tree[i * 2].v + tree[i * 2 + 1].v;
}

void update(int i, int tl, int tr, int l, int r)
{
    // printf("updating %d %d %d (%d %d)\n", i, tl, tr, l, r);
    if (tl == l && tr == r) {
        tree[i].flag = !tree[i].flag;
        tree[i].v = (tr - tl + 1) - tree[i].v;
        // printf("new = %d\n", tree[i].v);
        return;
    }

    push(i, tl, tr);
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        update(i * 2, tl, mid, l, r);
    } else if (l > mid) {
        update(i * 2 + 1, mid + 1, tr, l, r);
    } else {
        update(i * 2, tl, mid, l, mid);
        update(i * 2 + 1, mid + 1, tr, mid + 1, r);
    }
    // printf("old = %d ", tree[i].v);
    tree[i].v = tree[i * 2].v + tree[i * 2 + 1].v;
    // printf("new = %d\n", tree[i].v);
}

int query(int i, int tl, int tr, int p)
{
    // printf("q at %d %d %d %d\n", i, tl, tr, p);
    if (tl == tr) return tl;
    int mid = (tl + tr) / 2;
    push(i, tl, tr);
    if (tree[i * 2].v >= p) {
        return query(i * 2, tl, mid, p);
    } else {
        return query(i * 2 + 1, mid + 1, tr, p - tree[i * 2].v);
    }
}

int n, m, l;
int a, b;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> l;
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        update(1, 1, n, a, b);
        // printf("new = %d\n", tree[1].v);
        if (tree[1].v < l) {
            printf("AC?\n");
        } else {
            printf("%d\n", query(1, 1, n, l));
        }
    }
    return 0;
}
