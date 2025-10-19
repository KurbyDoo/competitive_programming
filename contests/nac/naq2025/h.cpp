#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

vector<pair<ld, ld>> people;
ll n, a, b;
ld balance = 0;
set<ll> allpos;
unordered_map<ll, ll> pos_to_idx;

struct node {
    ld total_weight = 0;
    ld total_people = 0;
    ll pos = 0;
};

node _tree[400010];

node merge(int i) {
    node merged;
    node a = _tree[i * 2];
    node b = _tree[i * 2 + 1];
    if (a.total_weight * b.total_people < b.total_weight * a.total_people)
        swap(a, b);
    merged.pos = a.pos;
    merged.total_people = a.total_people;
    merged.total_weight = a.total_weight;
    return a;
}

void build(ll i, ll l, ll r) {
    if (l == r) {
        _tree[i].total_weight = people[l - 1].second;
        _tree[i].total_people = 1;
        _tree[i].pos = people[l - 1].first;
        // printf("at %d %d-%d with %Lf %Lf\n", i, l, r, people[l - 1].second,
        //        _tree[i].total_people);
        return;
    }
    ll mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    _tree[i] = merge(i);
    // printf("at %d-%d with %Lf %Lf\n", l, r, _tree[i].total_weight,
    //        _tree[i].total_people);
}

void update(ll i, ll l, ll r, ll pos, ld add_weight, ld add_people) {
    // printf("at %d %d %d %d\n", i, l, r, pos);
    if (l == pos && pos == r) {
        _tree[i].total_weight += add_weight;
        _tree[i].total_people += add_people;
        return;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid) update(i * 2, l, mid, pos, add_weight, add_people);
    else update(i * 2 + 1, mid + 1, r, pos, add_weight, add_people);
    _tree[i] = merge(i);
}

node query(ll i, ll l, ll r, ll p) {
    // printf("q %d %d %d %d\n", i, l, r, p);
    if (l == p && r == p) {
        // printf("found at %d %d with idx = %d\n", i, l, _tree[i].idx);
        return _tree[i];
    }
    ll mid = (l + r) / 2;
    if (p <= mid)
        return query(i * 2, l, mid, p);
    else
        return query(i * 2 + 1, mid + 1, r, p);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        people.push_back({a, b});
        allpos.insert(a);
        balance += a * b;
    }

    sort(people.begin(), people.end());
    for (int i = 1; i <= n; i++) {
        pos_to_idx[people[i - 1].first] = i;
    }
    build(1, 1, n);

    if (balance == 0) {
        printf("0\n");
    }

    ld ans = 0;
    while (balance != 0) {
        node best = _tree[1];
        // printf("found best of %lld/%lld at %lld\n", best.total_weight,
        //        best.total_people, pos_to_idx[best.pos]);
        if (pos_to_idx[best.pos] == 1 && balance > 0) {
            // printf("jumping left %Lf\n", balance / best.total_weight);
            ans += abs((balance / best.total_weight) * best.total_people);
            balance = 0;
        } else if (pos_to_idx[best.pos] == n && balance < 0) {
            // printf("jumping right %Lf\n", balance / best.total_weight);
            ans += abs((balance / best.total_weight) * best.total_people);
            balance = 0;
        } else {
            auto it = allpos.find(best.pos);
            ll new_pos;
            if (balance > 0) { // move left
                new_pos = *prev(it);
            } else { // move right
                new_pos = *next(it);
            }
            // printf("next location is %lld\n", new_pos);
            ld max_dist = new_pos - best.pos;
            if (abs(max_dist * best.total_weight) > abs(balance)) {
                ans += abs((balance / best.total_weight) * best.total_people);
                balance = 0;
            } else {
                ans += abs(max_dist * best.total_people);
                balance += max_dist * best.total_weight;
                // printf("updating %d and %d\n", neighbour.idx, best.idx);
                update(1, 1, n, pos_to_idx[new_pos], best.total_weight,
                       best.total_people);
                update(1, 1, n, pos_to_idx[best.pos], -best.total_weight, 0);
                allpos.erase(it);
            }
        }
        // printf("new balance is %lld\n", balance);
    }
    printf("%.9Lf\n", ans);
    return 0;
}

// 7
// -2 1
// -1 1
// 0 2
// 1 1
// 2 1
// 3 1
// 4 1

// 2
// 0 3
// -100000000 1

// 6
// -4 1
// -3 1
// -2 1
// -1 1
// 0 3
// 100000000 1

// 2
// 0 7
// 100000000 1


// 1
// 10000000 100000

// 10
// -8 1
// -7 1
// -6 1
// -5 1
// -4 1
// -3 1
// -2 1
// -1 1
// 0 3
// 100000000 1
