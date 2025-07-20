#include <bits/stdc++.h>
using namespace std;
struct node {
    int v;
    int cnt;
} tree[4194304 + 10];
int skills[1048576 + 10];
int wins[1048576 + 10];
int n, m, a, b, c;
char op;
void build(int i, int l, int r)
{
    if (l == r)
    {
        tree[i].v = l;
        tree[i].cnt = 0;
        wins[l] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    if (skills[tree[i * 2].v] > skills[tree[i * 2 + 1].v])
    {
        tree[i].v = tree[i * 2].v;
        tree[i].cnt = tree[i * 2].cnt + 1;
        wins[tree[i * 2].v] = tree[i * 2].cnt + 1;
        wins[tree[i * 2 + 1].v] = tree[i * 2 + 1].cnt;
    }
    else
    {
        tree[i].v = tree[i * 2 + 1].v;
        tree[i].cnt = tree[i * 2 + 1].cnt + 1;
        wins[tree[i * 2].v] = tree[i * 2].cnt;
        wins[tree[i * 2 + 1].v] = tree[i * 2 + 1].cnt + 1;
    }
}
void update(int i, int tl, int tr, int p, int v)
{
    if (tl == p && tr == p)
    {
        tree[i].v = p;
        tree[i].cnt = 0;
        wins[p] = 0;
        skills[p] = v;
        return;
    }
    int mid = (tl + tr) / 2;
    if (p <= mid) {
        update(i * 2, tl, mid, p, v);
    } else {
        update(i * 2 + 1, mid + 1, tr, p, v);
    }
    if (skills[tree[i * 2].v] > skills[tree[i * 2 + 1].v])
    {
        tree[i].v = tree[i * 2].v;
        tree[i].cnt = tree[i * 2].cnt + 1;
        wins[tree[i * 2].v] = tree[i * 2].cnt + 1;
        wins[tree[i * 2 + 1].v] = tree[i * 2 + 1].cnt;
    }
    else
    {
        tree[i].v = tree[i * 2 + 1].v;
        tree[i].cnt = tree[i * 2 + 1].cnt + 1;
        wins[tree[i * 2].v] = tree[i * 2].cnt;
        wins[tree[i * 2 + 1].v] = tree[i * 2 + 1].cnt + 1;
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    n = 1 << n;
    for (int i = 1; i <= n; i++)
    {
        cin >> skills[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        cin >> op;
        if (op == 'S')
        {
            cin >> a;
            printf("%d\n", wins[a]);
        }
        else if (op == 'W')
        {
            printf("%d\n", tree[1].v);
        }
        else if (op == 'R')
        {
            cin >> a >> b;
            update(1, 1, n, a, b);
        }
    }
}