// Author: KurbyDoo
// Created: 2025-06-23 19:03:26
// D - Conflict 2
// https://atcoder.jp/contests/abc411/tasks/abc411_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll, ll> pll;
vector<pll> pcs[200010];
vector<pll> server;
string adds[200010], si;
int n, q, ti, pi, past;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    server.push_back({-1, -1, -1, -1});
    for (int i = 1; i <= n; i++) {
        pcs[i].push_back({-1, -1, -1, -1});
    }
    for (int i = 1; i <= q; i++) {
        cin >> ti;
        if (ti == 1) {
            cin >> pi;
            pcs[pi].push_back({server.size() - 1, -1, -1, -1});
        } else if (ti == 2) {
            cin >> pi >> si;
            adds[i] = si;
            reverse(adds[i].begin(), adds[i].end());
            pcs[pi].push_back({-1, i, pi, pcs[pi].size() - 1});
        } else {
            cin >> pi;
            server.push_back({pi, pcs[pi].size() - 1, -1, -1});
        }
    }

    int a, b, c, d;
    tie(a, b, c, d) = server.back();
    string out = "";
    while (a >= 0 || b >= 0) {
        if (a == -1) {
            out.append(adds[b]);
            tie(a, b, c, d) = pcs[c][d];
        } else if (b == -1) {
            tie(a, b, c, d) = server[a];
        } else {
            tie(a, b, c, d) = pcs[a][b];
        }
    }

    reverse(out.begin(), out.end());
    printf("%s\n", out.c_str());
    return 0;
}