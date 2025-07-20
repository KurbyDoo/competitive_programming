#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
struct trip {
    ll a, b, c;
};
ll n, m, u, v;
ll nums[200];
set<ll> factors[200];
map<ll, vector<ll>> used_factors[200];
map<ll, vector<trip>> opp_factors[200];
vector<ll> adj[200];
ll cur_itr = 1;

void find_factors(map<ll, vector<ll>> &used, map<ll, vector<trip>> &opp,
                  set<ll> &fact, ll number) {
    if (number == 1) return;
    for (ll i = 2; i < sqrtl(number) + 1; i++) {
        if (number % i == 0) {
            find_factors(used, opp, fact, number / i);
            fact.insert(i);
            used[i].push_back(0);
            opp[i].push_back(trip{-1, -1, -1});
            break;
        }
    }

    if (used.empty()) {
        fact.insert(number);
        used[number].push_back(0);
        opp[number].push_back(trip{-1, -1, -1});
    }
}

bool dfs(trip num) {
    if (used_factors[num.a][num.b][num.c] == cur_itr) {
        return false;
    }
    // printf("matching %lld %lld %lld\n", num.a, num.b, num.c);
    used_factors[num.a][num.b][num.c] = cur_itr;
    for (ll i : adj[num.a]) {
        for (int j = 0; j < used_factors[i][num.b].size(); j++) {
            trip match = opp_factors[i][num.b][j];
            // printf("attempting match %lld %lld %lld\n", match.a, match.b,
            //        match.c);
            if (match.a == -1 || dfs(match)) {
                opp_factors[i][num.b][j] = num;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        find_factors(used_factors[i], opp_factors[i], factors[i], nums[i]);
        // printf("Factors:\n");
        // for (ll f : factors[i]) {
        //     printf("    %lld %d\n", f, used_factors[i][f].size());
        // }
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2) continue;
        for (ll fact : factors[i]) {
            for (int j = 0; j < used_factors[i][fact].size(); j++) {
                cur_itr++;
                ans += dfs(trip{i, fact, j});
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}