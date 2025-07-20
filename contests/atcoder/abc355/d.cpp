#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> things;
vector<pii> toRemove;
int n, l, r;
ll ans = 0, cur = 0;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        things.push_back({l, 1});
        things.push_back({r + 1, -1});
    }

    sort(things.begin(), things.end());
    for (auto [a, b]: things) {
        if (b < 0) cur -= 1;
        if (b > 0) {
            ans += cur;
            cur += 1;

        }
    }
    printf("%lld\n", ans);

    return 0;
}
// 5
// 1 2
// 1 3
// 1 4
// 1 5
// 1 6


// 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6