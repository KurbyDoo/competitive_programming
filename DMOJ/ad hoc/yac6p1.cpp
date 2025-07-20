// KurbyDoo
// December 17th, 2023
// Yet Another Contest 6 P1 - No More Separation
// https://dmoj.ca/problem/yac6p1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            printf("%d %d\n", i, j);
            m -= 1;
            if (m == 0) return 0;
        }
    }
    return 0;
}