#include <bits/stdc++.h>
using namespace std;
typedef long double lld;
lld r, s, h, t, d, best_val;
int n1, n2, n3;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> r >> s >> h;
    d = 2.0L * atan(1) * 4.0L * r / s / h;
    best_val = 10.0L;
    if (d - floor(d) >= 0.5) {
        for (int i = 2; i <= 1000; i++) {
            for (int j = 2; i * j <= 1000; j++) {
                for (int k = 2; i * j * k <= 1000; k++) {
                    lld calc = abs(d - (ceil(d) - 1.0L/i + 1.0L/(j * i) - 1.0L/(i * j * k)));
                    if (calc < best_val) {
                        best_val = calc;
                        n1 = i;
                        n2 = j;
                        n3 = k;
                    }
                }
            }
        }
    } else {
        for (int i = 2; i <= 1000; i++) {
            for (int j = 2; i * j <= 1000; j++) {
                for (int k = 2; i * j * k <= 1000; k++) {
                    lld calc = abs(d - (floor(d) + 1.0L/i - 1.0L/(j * i) + 1.0L/(i * j * k)));
                    if (calc < best_val) {
                        best_val = calc;
                        n1 = i;
                        n2 = j;
                        n3 = k;
                    }
                }
            }
        }
    }
    printf("%d %d %d\n", n1, n1 * n2, n1 * n2 * n3);
    return 0;
}