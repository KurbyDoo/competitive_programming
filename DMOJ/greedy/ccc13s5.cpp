#include <bits/stdc++.h>
using namespace std;
int n, cost;
int main() {
    cin >> n;
    while (n != 1) {
        bool worked = false;
        for (int b = 1; b <= sqrt(n); b++) {
            if (n % (b + 1) == 0) {
                cost += b;
                n = b * (n / (b + 1));
                worked = true;
                break;
            }
        }
        if (!worked) {
            cost += n - 1;
            n -= 1;
        }
        // printf("n = %d\n", n);
    }
    printf("%d\n", cost);
}