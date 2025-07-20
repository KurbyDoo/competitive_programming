#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll inf = 1000000000;
ll capacity[710][710];
ll flow[710][710];
vector<ll> adj[710];
ll height[710];
ll excess[710];
ll n, m, d, sink, source, a, b, c, nn, ans = 0;
void push(ll u, ll v) {
    // printf("pushing %d -> %d\n", u, v);
    ll d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
}
void relable(ll u) {
    ll d = inf;
    // printf("relable %d\n", u);
    for (int i: adj[u]) {
        if (capacity[u][i] - flow[u][i] > 0) {
            d = min(d, height[i]);
        }
    }
    if (d < inf) {
        height[u] = d + 1;
    }
}
vector<ll> find_max(ll s, ll t) {
    vector<ll> max_heights;
    for (int i = 1; i < nn; i++) {
        if (excess[i] <= 0) continue;
        if (!max_heights.empty() && height[i] > height[max_heights[0]]) max_heights.clear();
        if (max_heights.empty() || height[i] == height[max_heights[0]]) max_heights.push_back(i);
    }
    return max_heights;
}
ll max_flow(ll expected, ll s, ll t) {
    for (int i = 0; i <= nn; i++) {
        height[i] = 0;
        excess[i] = 0;
        for (int j: adj[i]) {
            flow[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        capacity[i][sink] = expected;
    }
    excess[s] = inf;
    height[s] = nn;

    for (int i: adj[s]) {
        push(s, i);
    }

    vector<ll> current;
    while (!(current = find_max(s, t)).empty()) {
        for (ll i: current) {
            // printf("attempting push on %d\n", i);
            bool pushed = false;
            for (int j: adj[i]) {
                if (!excess[i]) break;
                if (capacity[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1) {
                    push(i, j);
                    pushed = true;
                }

            }
            if (!pushed) {
                relable(i);
                break;
            }
        }
    }
    // printf("max flow to %d is %d\n", t, excess[t]);
    return excess[t];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    source = n + m + 1;
    sink = 0;
    d = 0;
    nn = n + m + 1;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        capacity[n + i][a] = c;
        capacity[n + i][b] = c;
        capacity[source][n + i] = c;
        adj[n + i].push_back(a);
        adj[n + i].push_back(b);
        adj[a].push_back(n + i);
        adj[b].push_back(n + i);
        adj[n + i].push_back(source);
        adj[source].push_back(n + i);
        ans += c;
    }

    for (int i = 1; i <= n; i++) {
        adj[i].push_back(sink);
        adj[sink].push_back(i);
    }
    ll ld = 0;
    ll rd = ans;
    while (ld < rd) {
        ll mid = (ld + rd + 1) / 2;
        // printf("mid = %d\n", mid);
        ll cur_flow = max_flow(mid, source, sink);
        if (cur_flow == n * mid) {
            ld = mid;
        } else {
            rd = mid - 1;
        }
    }
    printf("%lld\n", ans - ld * n);
}