#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
// unordered_map<ll, vector<pii>> graph;
vector<array<ll, 3>> edges;
ll m, n, k;
ll u, v, w;
ll ans = 1e17;

void dfs(ll visited, ll cur_cost){
    // printf("at %lld visited = %lld\n", cur_cost, visited);
    if (visited == (1 << (n + 1)) - 1){
        ans = min(ans, cur_cost % k);
        return;
    }

    for (auto [a, b, c]: edges){
        if ((visited & (1 << a)) && !(visited & (1 << b))){
            dfs(visited | (1 << b), cur_cost + c);
        }
        if ((visited & (1 << b)) && !(visited & (1 << a))){
            dfs(visited | (1 << a), cur_cost + c);
        }
    }
    // for (int i = 1; i <= n; i++){
    //     if (visited & (1 << i)){
    //         for (auto [e, c]: graph[i]) {
    //             if (!(visited & (1 << e))){
    //                 dfs(visited | (1 << e), cur_cost + c);
    //             }
    //         }
    //     }
    // }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        if (v < u) swap(u, v);
        edges.push_back({u, v, w});
    }

    ll visited = 1;
    visited |= (1 << 1);
    dfs(visited, 0);
    printf("%lld\n", ans);

    return 0;
}