#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, m;
string target[510];
bool exists[510];
int max_length = 0;
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> target[i];
        exists[i] = false;
    }

    int max_length = 0;
    int cur_length = 0;
    string cur_string;
    for (int i = 0; i < m; i++) {
        cur_length = 0;
        for (int j = 0; j < n; j++) {
            cin >> cur_string;
            if (cur_string == target[j]) {
                exists[j] = true;
                cur_length += 1;
            }
        }
        max_length = max(max_length, cur_length);
    }

    for (int i = 0; i < n; i++) {
        if (exists[i]) continue;
        printf("-1\n");
        return;
    }
    // printf("best string = %d\n", max_length);
    printf("%d\n", n + (n - max_length) * 2);
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