# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll nums[600000];
ll variance[3000000];
ll winner[3000000];

void build_tree(ll i, ll l, ll r) {
    if (l == r) {
        variance[i] = 0;
        winner[i] = nums[l];
        return;
    }

    ll mid = (l + r) / 2;
    build_tree(i * 2, l, mid);
    build_tree(i * 2 + 1, mid + 1, r);

    winner[i] = max(winner[i * 2], winner[i * 2 + 1]);
    variance[i] = variance[i * 2] + variance[i * 2 + 1];
    variance[i] += (winner[i * 2 + 1] - winner[i * 2]) * (winner[i * 2 + 1] - winner[i * 2]);

    return;
}

void update(ll i, ll l, ll r, ll a, ll b) {
    if (l == r) {
        variance[i] = 0;
        winner[i] = nums[l];
        return;
    }

    ll mid = (l + r) / 2;
    if (a <= mid && b <= mid) {
        update(i * 2, l, mid, a, b);
    } else if (a > mid && b > mid) {
        update(i * 2 + 1, mid + 1, r, a, b);
    } else {
        update(i * 2, l, mid, a, a);
        update(i * 2 + 1, mid + 1, r, b, b);
    }

    winner[i] = max(winner[i * 2], winner[i * 2 + 1]);
    variance[i] = variance[i * 2] + variance[i * 2 + 1];
    variance[i] += (winner[i * 2 + 1] - winner[i * 2]) * (winner[i * 2 + 1] - winner[i * 2]);

    return;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    // n = 100000;
    ll num = n * (n + 1) / 2;
    for (ll i = 2; i <= n; i++) {
        cin >> nums[i];
        // nums[i] = i;
        num -= nums[i];
    }

    nums[1] = num;

    build_tree(1, 1, n);

    for (ll i = 1; i <= n; i++) {
        printf("%lld ", variance[1]);
        swap(nums[i], nums[i + 1]);
        update(1, 1, n, i, i + 1);
    }
    return 0;
}