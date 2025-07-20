// KurbyDoo
// December 17th, 2023
// DMOPC '23 Contest 1 P1 - Peak Grid
// https://dmoj.ca/problem/dmopc23c1p1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    if (k == 0) {
        printf("-1\n");
        return 0;
    }

    int cur = n * n - k;
    int big = n * n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (x == y && k > 0) {
                printf("%d ", big);
                big -= 1;
                k -= 1;
            } else {
                printf("%d ", cur);
                cur -= 1;
            }
        }
        printf("\n");
    }
    return 0;
}