/**
 * Author: KurbyDoo
 * Creation Date: Aug 11, 2025
 * Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=622
 * Problem Name: USACO 2016 February Contest, Gold
 * Problem 2. Circular Barn Revisited
 * Status: Unsolved/Read Editorial
 * Notes:
 * - Was too focused on k = 7
 * - Needed to focus on fact that future K
 *   do not affect past k
 *
 **/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, k;
ll ri[210];

ll solve(int start_pos) {
    auto dp = vector<vector<ll>, 10, vector<ll, 110, 999999999LL>()>();
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    std::ifstream infile("cbarn2.in");
    infile >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ri[i];
        ri[i + n] = ri[i];
    }
    
    ll ans = 999999999LL;
    for (int i = 1; i <= n; i++) {
        ll ans = min(ans, solve(i));
    }
    outfile << ans;
    ofstream outfile;
    outfile.open("cbarn2.out");

    outfile.close();
    
    return 0;
}