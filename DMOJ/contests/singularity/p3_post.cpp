#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m, p;
unordered_map<int, vector<int>> graph;
unordered_map<ll, int> loc_id;
set<pll> to_check;
set<ll> visited_right;
set<ll, greater<ll>> visited_left;
set<ll> inq_right;
set<ll, greater<ll>> inq_left;
ll loc[1000010];
ll dist[1000010];
ll parent_count[1000010];

ll find_close(int i) {
    auto ls = visited_left.lower_bound(loc[i]); ll l = *ls;
    auto rs = visited_right.lower_bound(loc[i]); ll r = *rs;
    if (ls == visited_left.end()) l = *rs;
    if (rs == visited_right.end()) r = *ls;
    // printf("close for %d = %d\n", i, min(abs(loc[i] - l.first), abs(loc[i] - r.first)));
    return min(abs(loc[i] - l), abs(loc[i] - r));
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> loc[i];
        loc_id[loc[i]] = i;
        dist[i] = -1;
    }
    dist[p] = 0;
    visited_left.insert(loc[p]);
    visited_right.insert(loc[p]);
    // to_check.insert({0, p});
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        if (b == p) continue;
        graph[b].push_back(a);
        parent_count[a] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent_count[i] == 0)
        {
            to_check.insert({find_close(i), i});
            inq_left.insert(loc[i]);
            inq_right.insert(loc[i]);
        }
    }

    while (!to_check.empty())
    {
        // printf("size = %d\n", to_check.size());
        pll best = *to_check.begin();
        ll id = best.second;
        to_check.erase(to_check.begin());
        if (dist[id] != -1 && id != p) continue;

        dist[id] = find_close(id);
        // printf("dist[%d] = %lld\n", id, dist[id]);
        visited_left.insert(loc[id]);
        visited_right.insert(loc[id]);
        // printf("l %d and r %d of %d\n", l, r, id);
        for (int e: graph[id])
        {
            parent_count[e] -= 1;
            if (parent_count[e] == 0)
            {
                to_check.insert({find_close(e), e});
                inq_left.insert(loc[id]);
                inq_right.insert(loc[id]);
            }
        }
        auto ls = inq_left.upper_bound(loc[id]);
        auto rs = inq_right.upper_bound(loc[id]);
        ll l = loc_id[*ls]; ll r = loc_id[*rs];

        if (ls != inq_left.end()) {
            if (dist[l] == -1) to_check.insert({find_close(l), l});
        }
        if (rs != inq_right.end()) {
            if (dist[r] == -1) to_check.insert({find_close(r), r});
        }
    }

    ll fuel = 0;
    for (int i = 1; i <= n; i++)
    {
        // printf("%lld ", dist[i]);
        fuel = max(fuel, dist[i]);
    }
    // printf("\n");
    printf("%lld\n", fuel);
    return 0;
}
// 6 0 1
// 3 9 10 4 1 2

// 7 3 4
// 1 2 3 4 5 6 7
// 2 5
// 5 3
// 7 1

// 5 2 3
// 1 2 5 7 9
// 2 5
// 4 3

// 6 2 4
// 150 200 599 600 850 1100
// 5 3
// 2 6

// 5 2 1
// 1 2 3 4 100
// 2 3
// 4 2

// 5 3 2
// 2 5 6 7 10
// 3 5
// 3 1
// 4 1

// 5 3 2
// 10 6 7 5 2
// 2 1
// 2 5
// 3 5

// 9 12 2
// 99 100 120 130 140 150 199 200 201
// 4 1
// 5 4
// 5 1
// 3 6
// 7 1
// 7 2
// 7 3
// 7 4
// 7 5
// 7 6
// 4 3
// 5 3