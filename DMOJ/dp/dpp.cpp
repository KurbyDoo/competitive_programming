// Kurbydoo
// September 5th, 2023
// CCC '23 S3 - Palindromic Poster
// https://dmoj.ca/problem/ccc23s3
#include <bits/stdc++.h>
using std::cin;
using std::max;
using std::memset;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;

const int mod = 1e9 + 7;

int n;
unordered_map<int, vector<int>> graph;

pair<ll, ll> dfs(int node, int past) {
    ll on = 1;
    ll off = 1;

    for (int e: graph[node]) {
        if (e != past) {
            pair<ll, ll> result = dfs(e, node);
            on = ((on % mod) * (result.second % mod)) % mod;
            off = ((off % mod) * (result.first % mod)) % mod;
        }
    }

    ll total = (on + off) % mod;
    return {total, off};
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printf("%llu\n", dfs(1, -1).first);

    return 0;
}