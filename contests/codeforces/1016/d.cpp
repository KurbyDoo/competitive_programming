#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;

void solve() {
    int n, q, a, b;
    char c;
    cin >> n >> q;
    while (q--) {
        cin >> c;
        if (c == '-') {
            cin >> a >> b;
            printf("-> %d %d\n", a, b);
        } else {
            cin >> a;
            printf("<- %d\n", a);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}