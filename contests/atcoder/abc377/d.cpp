#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, m, li, ri, ans, recent;
vector<pii> thingsnonameconflict;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> li >> ri;
        thingsnonameconflict.push_back({ri, li});
    }

    sort(thingsnonameconflict.begin(), thingsnonameconflict.end(), greater<pii>());

    for (int i = 1; i <= m; i++) {
        while (thingsnonameconflict.size() > 0 && thingsnonameconflict.back().first <= i) {
            recent = max(recent, thingsnonameconflict.back().second);
            thingsnonameconflict.pop_back();
        }
        ans += i - recent;
    }
    printf("%lld\n", ans);

    return 0;
}