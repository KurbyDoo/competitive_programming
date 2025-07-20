// KurbyDoo
// December 17th, 2023
// DMOPC '16 Contest 4 P1 - Fast Exponents
// https://dmoj.ca/problem/dmopc16c4p1
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
set<ll> powers;
ll n, x;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    ll num = 1;
    for (int i = 0; i <= 63; i++) {
        powers.insert(num);
        num *= 2;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (powers.find(x) == powers.end()) {
            printf("F\n");
        } else {
            printf("T\n");
        }
    }

    return 0;
}