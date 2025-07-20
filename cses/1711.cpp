#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll capacity[510][510];
bool dir[510][510];
ll par[510];
vector<ll> adj[510];
vector<ll> out[510];
// vector<vector<int>> out;

ll n, m, ans, s, t, ai, bi; 

int bfs(int s, int t) {
    fill(par, par + n + 5, -1);
    queue<pair<int, int>> q;
    q.push({s, 1000000000});
    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (int e: adj[cur]) {
            if (par[e] == -1 && capacity[cur][e] > 0) {
                flow = min(flow, capacity[cur][e]);
                par[e] = cur;
                if (e == t) {
                    return flow;
                }
                q.push({e, flow});
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi;
        adj[ai].push_back(bi);
        adj[bi].push_back(ai);
        capacity[ai][bi] = 1;
        dir[ai][bi] = 1;
    }

    ll next_flow = 0;
    while (next_flow = bfs(1, n)) {
        ans += next_flow;
        vector<int> order;
        ll cur = n;
        while (cur != 1) {
            capacity[par[cur]][cur] -= next_flow;
            capacity[cur][par[cur]] += next_flow;
            if (!dir[par[cur]][cur]) {
                // printf("removed backwards edge %d %d %d\n", par[cur], cur, out[par[cur]].size());
                // remove(out[par[cur]].begin(), out[par[cur]].end(), cur);
                out[par[cur]].erase(find(out[par[cur]].begin(), out[par[cur]].end(), cur));
                // printf("siz = %d\n", out[par[cur]].size());
            } else {
                // printf("added %d to %d\n", par[cur], cur);
                out[cur].push_back(par[cur]);
            }
            cur = par[cur];
        }
    }

    printf("%lld\n", ans);
    while (!out[n].empty()) {
        ll cur = n;
        vector<ll> order;
        while (cur != 1) {
            // printf("at %d len = %d\n", cur, out[cur].size());
            order.push_back(cur);
            ll next = out[cur].back();
            out[cur].pop_back();
            cur = next;
        }
        order.push_back(1);
        printf("%lld\n", order.size());
        while (!order.empty()) {
            printf("%lld ", order.back());
            order.pop_back();
        }
        printf("\n");
    }
}