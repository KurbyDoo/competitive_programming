#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p, l, r;
unordered_map<int, vector<int>> graph;
unordered_map<ll, int> loc_id;
set<ll> valid_right;
set<ll, greater<ll>> valid_left;
ll loc[1000010];
ll dist[1000010];
ll parent[1000010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> p;
    l = p;
    r = p;
    for (int i = 1; i <= n; i++)
    {
        cin >> loc[i];
        loc_id[loc[i]] = i;
        dist[i] = -1;
    }
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        if (b == p)
            continue;
        graph[b].push_back(a);
        parent[a]++;
    }
    dist[p] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 0 && i != p)
        {
            valid_left.insert({loc[i]});
            valid_right.insert({loc[i]});
        }
    }
    while (true)
    {
        auto lit = valid_left.upper_bound(loc[r]);
        ll left = *lit;
        auto rit = valid_right.upper_bound(loc[l]);
        ll right = *rit;
        // printf("l = %d, r = %d\n", left, right);
        // printf("sl = %d, sr = %d\n", valid_left.size(), valid_right.size());
        if (lit == valid_left.end() && rit == valid_right.end())
            break;
        if (lit == valid_left.end())
            left = right;
        if (rit == valid_right.end())
            right = left;
        ll best = -1;
        int id = -1;
        if (loc[l] <= left && left <= loc[r])
        {
            best = left;
            id = loc_id[best];
            dist[id] = 0;
        }
        else if (loc[l] <= right && right <= loc[r])
        {
            best = right;
            id = loc_id[best];
            dist[id] = 0;
        }
        else
        {
            if (loc[l] - left < right - loc[r])
            {
                best = left;
            }
            else
            {
                best = right;
            }
            id = loc_id[best];
            dist[id] = min(abs(best - loc[l]), abs(best - loc[r]));
        }

        // printf("best = %d id = %d dist = %d\n", best, id, dist[id]);
        // printf("before | sl = %d, sr = %d\n", valid_left.size(), valid_right.size());
        valid_left.erase(best);
        valid_right.erase(best);
        // printf("after  | sl = %d, sr = %d\n", valid_left.size(), valid_right.size());
        // for (int i : valid_left)
        // {
        //     printf("%d ", i);
        // }
        // printf("\n");
        // for (int i : valid_right)
        // {
        //     printf("%d ", i);
        // }
        // printf("\n");
        if (loc[id] <= loc[l])
        {
            l = id;
        }
        if (loc[id] >= loc[r])
        {
            r = id;
        }

        for (int e : graph[id])
        {
            parent[e]--;
            if (parent[e] == 0)
            {
                // printf("added loc[%d] = %d\n", e, loc[e]);
                valid_left.insert(loc[e]);
                valid_right.insert(loc[e]);
            }
        }
    }

    ll max_dist = 0;
    for (int i = 1; i <= n; i++)
    {
        max_dist = max(max_dist, dist[i]);
    }
    printf("%lld\n", max_dist);
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