#include <bits/stdc++.h>
using namespace std;
int st[1010][1010][11][11] int n;
void init(std::vector<std::vector<int>> arr) {
    int n = arr[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st[i][j][0][0] = arr[i][j];
        }
    }

    for (int k2 = 1; k2 <= log2(n); k2++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= log2(n); k++) {
                for (int i = 1; i <= n; i++) {
                    st[i][j][k][k2] = min(st[i][j][k - 1][k2 - 1], st[i][j][k][k2]);
                    st[i][j][k][k2] = min(st[i - (1 << (k - 1))][j][k - 1][k2 - 1], st[i][j][k][k2]);
                    st[i][j][k][k2] = min(st[i][j][k - 1][k2 - 1], st[i][j][k][k2]);
                    st[i][j][k][k2] = min(st[i][j][k - 1][k2 - 1], st[i][j][k][k2]);
                }
            }
        }
    }
}

int query(int a, int b, int c, int d) {

}
