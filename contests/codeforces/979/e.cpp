#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;
void solve() {
    ll n;
    cin >> n;
    ll cnt[n + 1];
    fill(cnt, cnt + n + 1, 0);
    ll max_score = 0;
    for (int a, i = 0; i < n; i++) {
        cin >> a;
        cnt[a]++;
    }
    ll min_count = cnt[0];
    for (int i = 0; i < n; i++) {
        min_count = min(min_count, cnt[i]);
        max_score += min_count;
    }
    printf("max score = %d\n", max_score);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();

    }
    return 0;
}