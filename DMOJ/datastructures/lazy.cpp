// Kurbydoo
// March 31, 2023
// Strict Evaluation
// https://dmoj.ca/problem/lazy
#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long ll;

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::unordered_map;
using std::vector;

struct node
{
    ll value, l, r;
    bool flag = false;
    bool addFlag = false;
    bool setFlag = false;
    ll flagValue = 0;
};

int n, q;
int a, b, c, d;

node tree[400010];
int nums[100010];

void push(ll i)
{
    if (tree[i].setFlag)
    {
        tree[i * 2].setFlag = true;
        tree[i * 2].value = tree[i].value;
        tree[i * 2 + 1].setFlag = true;
        tree[i * 2 + 1].value = tree[i].value;
        tree[i].setFlag = false;
        tree[i].addFlag = false;
        tree[i].flagValue = 0;
    }
    else if (tree[i].addFlag)
    {
        tree[i * 2].addFlag = true;
        tree[i * 2].value += tree[i].flagValue;
        tree[i * 2].flagValue += tree[i].flagValue;
        tree[i * 2 + 1].addFlag = true;
        tree[i * 2 + 1].value += tree[i].flagValue;
        tree[i * 2 + 1].flagValue += tree[i].flagValue;
        tree[i].addFlag = false;
        tree[i].flagValue = 0;
    }
}

void build(ll i, int left, int right)
{
    tree[i].l = left;
    tree[i].r = right;
    // printf("%d %d %d\n", i, left, right);
    if (left == right)
    {
        // printf("set %d to %d\n", i, nums[left]);
        tree[i].value = nums[left];
        return;
    }

    int mid = (left + right) / 2;
    build(i * 2, left, mid);
    build(i * 2 + 1, mid + 1, right);

    tree[i].value = min(tree[i * 2].value, tree[i * 2 + 1].value);
    // printf("set %d to %d\n", i, tree[i].value);
}

void increment(ll i, int qL, int qR, ll value)
{
    // printf("inc at %d %d (%d %d) (%d -> %d)\n", qL, qR, tree[i].l, tree[i].r, tree[i].value, value);

    if (tree[i].l == qL && tree[i].r == qR)
    {
        tree[i].addFlag = true;
        tree[i].value += value;
        tree[i].flagValue += value;
        // printf("new value is %d\n", tree[i].value);

        return;
    }

    push(i);
    int mid = (tree[i].l + tree[i].r) / 2;

    if (qR <= mid)
        increment(i * 2, qL, qR, value);
    else if (qL > mid)
        increment(i * 2 + 1, qL, qR, value);
    else
    {
        increment(i * 2, qL, mid, value);
        increment(i * 2 + 1, mid + 1, qR, value);
    }
    tree[i].value = min(tree[i * 2].value, tree[i * 2 + 1].value);
    // printf("new value is %d\n", tree[i].value);
}

void set(ll i, int qL, int qR, ll value)
{
    // printf("set at %d %d (%d %d) (%d -> %d)\n", qL, qR, tree[i].l, tree[i].r, tree[i].value, value);

    if (tree[i].l == qL && tree[i].r == qR)
    {
        tree[i].setFlag = true;
        tree[i].value = value;
        // printf("new value is %d\n", tree[i].value);
        return;
    }

    push(i);
    int mid = (tree[i].l + tree[i].r) / 2;

    if (qR <= mid)
        set(i * 2, qL, qR, value);
    else if (qL > mid)
        set(i * 2 + 1, qL, qR, value);
    else
    {
        set(i * 2, qL, mid, value);
        set(i * 2 + 1, mid + 1, qR, value);
    }
    tree[i].value = min(tree[i * 2].value, tree[i * 2 + 1].value);
    // printf("new value is %d\n", tree[i].value);
}

ll query(ll i, int qL, int qR)
{
    // printf("value at %d %d is %d\n", qL, qR, tree[i].value);
    if (tree[i].l == qL && tree[i].r == qR)
    {
        return tree[i].value;
    }

    push(i);
    int mid = (tree[i].l + tree[i].r) / 2;

    if (qR <= mid)
        return query(i * 2, qL, qR);
    else if (qL > mid)
        return query(i * 2 + 1, qL, qR);
    else
    {
        return min(query(i * 2, qL, mid), query(i * 2 + 1, mid + 1, qR));
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    build(1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            cin >> d;
            increment(1, b - 1, c - 1, d);
        }
        else if (a == 2)
        {
            cin >> d;
            set(1, b - 1, c - 1, d);
        }
        else
        {
            printf("%llu\n", query(1, b - 1, c - 1));
        }
    }

    return 0;
}

// 5 3
// 1 2 3 4 5
// 3 2 4
// 2 2 4 10
// 3 2 5

// 5 3
// 1 2 3 4 5
// 1 1 5 0
// 1 1 4 10
// 3 1 5

// 5 13
// 1 2 3 4 5
// 2 1 5 0
// 3 1 1
// 3 2 2
// 3 3 3
// 3 4 4
// 3 5 5
// 1 1 4 10
// 3 1 5
// 3 1 1
// 3 2 2
// 3 3 3
// 3 4 4
// 3 5 5

// 5 7
// 1 2 3 4 5
// 2 1 5 0
// 1 1 4 10
// 1 3 5 6
// 3 1 4
// 3 1 5
// 1 2 5 100
// 3 1 5

// 5 6
// 1 2 3 4 5
// 2 2 5 1
// 3 1 5
// 1 1 4 10
// 3 1 5
// 1 2 5 10
// 3 1 5

// 5 9
// 1 2 3 4 5
// 3 1 1
// 1 1 5 10
// 3 1 1
// 3 1 3
// 3 1 1
// 3 3 5
// 1 2 5 100
// 3 1 3
// 3 3 5

// 5 6
// 1 2 3 4 5
// 1 2 5 10
// 3 1 3
// 3 3 5
// 2 2 5 100
// 3 1 3
// 3 3 5