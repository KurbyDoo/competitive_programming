#include <bits/stdc++.h>
using namespace std;
int bar[3][200010];
int n;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bar[i][j];
        }
    }

    if (n == 2) {
        int b1 = bar[0][0], b2 = bar[1][0], b3 = bar[0][1], b4 = bar[1][1];
        if (b1 == b2 && b2 == b3 && b3 == b4) {
            printf("4\n");
        } else if (b1 == b2 && b3 + b4 == b2 * 2) {
            printf("3\n");
        } else if (b1 == b3 && b4 + b2 == b1 * 2) {
            printf("3\n");
        } else if (b4 == b2 && b3 + b1 == b2 * 2) {
            printf("3\n");
        } else if (b4 == b3 && b1 + b2 == b4 * 2) {
            printf("3\n");
        } else if (b3 + b4 == b1 + b2) {
            printf("2\n");
        } else if (b3 + b1 == b4 + b2) {
            printf("2\n");
        } else if (b1 + b2 + b3 == b4 * 3) {
            printf("2\n");
        } else if (b4 + b2 + b3 == b1 * 3) {
            printf("2\n");
        } else if (b1 + b4 + b3 == b2 * 3) {
            printf("2\n");
        } else if (b1 + b2 + b4 == b3 * 3) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    
    }
    // int ans = 0;
    // int l = 1, r = total / n;
    // while (l < r) {
    //     int mid = (l + r + 1) / 2;
    //     int res = try_mean(mid);
    //     if (res >= ans) {
    //         l = mid;
    //     } else {
    //         r = mid - 1;
    //     }
    // }
}