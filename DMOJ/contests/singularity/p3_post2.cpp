#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m, p;
unordered_map<int, vector<int>> graph;
priority_queue<pll, vector<pll>, greater<pll>> to_check;
set<pll> valid_right;
set<pll, greater<pll>> valid_left;
ll loc[1000010];
ll dist[1000010];
ll parent_count[1000010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> loc[i];
        dist[i] = -1;
    }
    dist[p] = 0;
    valid_left.insert({loc[p], p});
    valid_right.insert({loc[p], p});
    to_check.push({0, p});
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        graph[b].push_back(a);
        parent_count[a] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent_count[i] == 0)
        {
            to_check.push({abs(loc[i] - loc[p]), i});
        }
    }

    while (!to_check.empty())
    {
        pll best = to_check.top();
        ll id = best.second;
        to_check.pop();

        auto ls = valid_left.lower_bound({loc[id], id});
        auto rs = valid_right.lower_bound({loc[id], id});
        pll l = *ls;
        pll r = *rs;
        if (ls == valid_left.end()) l = *rs;
        if (rs == valid_right.end()) r = *ls;
        dist[id] = min(abs(loc[id] - l.first), abs(loc[id] - r.first));
        valid_left.insert({loc[id], id});
        valid_right.insert({loc[id], id});
        // printf("best = %d\n", best);
        // printf("dist = %lld\n", dist[best]);
        for (int e : graph[id])
        {
            parent_count[e] -= 1;
            if (parent_count[e] == 0)
            {
                ls = valid_left.lower_bound({loc[e], e});
                rs = valid_right.lower_bound({loc[e], e});
                l = *ls;
                r = *rs;
                if (ls == valid_left.end()) l = *rs;
                if (rs == valid_right.end()) r = *ls;
                to_check.push({min(abs(loc[e] - l.first), abs(loc[e] - r.first)), e});
            }
        }
    }

    ll fuel = 0;
    for (int i = 1; i <= n; i++)
    {
        fuel = max(fuel, dist[i]);
    }
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