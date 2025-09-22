/**
 * Author: KurbyDoo
 * Creation Date: Sep 02, 2025
 * Problem Link: https://atcoder.jp/contests/abc416/tasks/abc416_e
 * Problem Name: E - Development 
 * Status: Unsolved
 * Notes:
 * 	
 * 	
 * 	
 * 	
**/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m, k, q, t;
ll ai, bi, ci, tti, xi, yi, ti, di;
vector<pll> adj[510];
bool is_airport[510];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ai >> bi >> ci;
        adj[ai].push_back({bi, ci});
        adj[bi].push_back({ai, ci});
    }
    cin >> k >> t;
    for (int i = 0; i < k; i++) {
        cin >> di;
        is_airport[di] = true;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> tti;
        switch (tti)
        {
        case 1:
            cin >> xi >> yi >> ti;
            adj[xi].push_back({yi, ti});
            adj[yi].push_back({xi, ti});
            break;
        case 2:
            cin >> xi;
            is_airport[xi] = true;
            break;
        default:
            printf("%lld\n", solve())
            break;
        }
    }

    
    return 0;
}