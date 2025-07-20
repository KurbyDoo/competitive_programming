#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<pair<int, int>> bc;
    for (int i = 0; i < n; i++) {
        if (i == 0 || b[i] != b[i - 1]) bc.push_back({b[i], 0});
    }
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (ind != bc.size() && a[i] == bc[ind].first) {
            bc[ind].second = i;
            ind++;
        }
    }
    if (ind != bc.size()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int mov[n];
    ind = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && b[i] != b[i - 1]) ind++;
        mov[i] = bc[ind].second;
    }
    vector<pair<int, int>> itv;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != b[s]) {
            itv.push_back({s, i - 1});
            s = i;
        }
    }
    itv.push_back({s, n - 1});
    vector<pair<int, int>> ls, rs;
    for (auto p : itv) {
        int l = p.first;
        int r = p.second;
        ind = mov[l];
        if (l == r && l == ind) continue;
        if (ind <= l) {
            rs.push_back({ind, r});
        } else if (ind >= r) {
            ls.push_back({l, ind});
        } else {
            rs.push_back({ind, r});
            ls.push_back({l, ind});
        }
    }
    reverse(rs.begin(), rs.end());
    cout << ls.size() + rs.size() << "\n";
    for (auto p : ls) {
        cout << "L " << p.first << " " << p.second << "\n";
    }
    for (auto p : rs) {
        cout << "R " << p.first << " " << p.second << "\n";
    }
}
// TEST CASES
/*
14
2 3 4 8 9 2 3 6 8 3 7 1 4 1
2 2 3 4 2 2 2 2 3 3 1 4 1 1
*/

// 7
// 1 1 1 2 3 2 1
// 1 3 2 1 1 1 1

// 10
// 1 2 3 2 1 1 2 3 2 1
// 2 3 3 3 2 3 2 1 1 1