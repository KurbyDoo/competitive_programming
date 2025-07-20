#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
unordered_map<int, vector<int>[26]> graph;
unordered_map<int, vector<int>[26]> rgraph;
int n;
int ans[110][110];

void solve(int sn, int en) {
    if (ans[sn][en] != 99999) return;
    int min_length = 99999;
    for (int c = 0; c < 26; c++) {
        for (int out_sn: graph[sn][c]) {
            for (int inc_en: rgraph[en][c]) {
                min_length = min(min_length, ans[out_sn][inc_en] + 2);
            }
        }
    }
    ans[sn][en] = min_length;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            ans[i][j] = 99999;
            if (s[j - 1] == '-') continue;
            ans[i][j] = 1;
            graph[i][s[j - 1] - 'a'].push_back(j);
            rgraph[j][s[j - 1] - 'a'].push_back(i);
        }
        ans[i][i] = 0;
    }

    for (int l = 1; l <= 15 * n; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                solve(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", ans[i][j] == 99999 ? -1 : ans[i][j]);
        }
        printf("%d\n", ans[i][n] == 99999 ? -1 : ans[i][n]);
    }
    return 0;
}
// 7
// -------
// a---c--
// -b-----
// --c----
// ---d---
// -b-----
// -----a-

// 8
// --------
// a-------
// -b------
// --b-----
// ---b----
// ----b---
// -----cb-
// ------a-