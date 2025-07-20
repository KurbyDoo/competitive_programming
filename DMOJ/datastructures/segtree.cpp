// Kurbydoo
// March 24th, 2023
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;
using std::min;
using std::max;

int n, m;
int b, c;
int tree[400010];
int nums[100010];

void build(int index, int left, int right) {
    if (left == right) {
        // printf("setting %d %d %d\n", index, left, right);
        tree[index] = nums[left];
    }
    else {
        int mid = (left + right) / 2;
        build(index * 2, left, mid);
        build(index * 2 + 1, mid + 1, right);
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
}

void update(int index, int left, int right, int pos, int newValue) {
    // printf("updating %d %d %d\n", left, right, pos);
    if (left == right) {
        // printf("updated\n");
        tree[index] = newValue;
    }

    else {
        int mid = (left + right) / 2;
        if (mid < pos) update(index * 2 + 1, mid + 1, right, pos, newValue);
        else update(index * 2, left, mid, pos, newValue);
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
}

int query(int index, int left, int right, int qLeft, int qRight) {
    // printf("querying %d %d %d %d %d\n", index, left, right, qLeft, qRight);
    if (qLeft > qRight) {
        // printf("exiting\n");
        return INT32_MAX;
    }
    if (left == qLeft && right == qRight) {
        // printf("found %d\n", tree[index]);
        return tree[index];
    }

    else {
        int mid = (left + right) / 2;
        int best = min(query(index * 2, left, mid, qLeft, min(qRight, mid)),
        query(index * 2 + 1, mid + 1, right, max(qLeft, mid + 1), qRight));
        // printf("%d\n", best);
        return best;
    }
}


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (a == "Q") printf("%d\n", query(1, 0, n - 1, b, c));
        else update(1, 0, n - 1, b, c);
    }
    
    return 0;
}

// 5 10
// 1 2 3 4 5
// Q 0 0
// Q 1 1
// Q 2 2
// Q 3 3
// Q 4 4
// Q 0 3
// M 0 5
// Q 0 0
// Q 0 2
// Q 0 4

