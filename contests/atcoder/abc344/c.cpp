#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
unordered_map<int, bool> possible;
int a[110], b[110], c[110];
int n, m, l, q;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> c[i];
    }

    for (int a_i = 0; a_i < n; a_i++) {
        for (int b_i = 0; b_i < m; b_i++) {
            for (int c_i = 0; c_i < l; c_i++) {
                possible[a[a_i] + b[b_i] + c[c_i]] = true;
            }
        }
    }

    cin >> q;
    for (int i = 0, temp; i < q; i++) {
        cin >> temp;
        printf(possible[temp] ? "Yes\n" : "No\n");
    }

        return 0;
}