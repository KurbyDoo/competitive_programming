#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int things[11];
int costA[11];
int costB[11];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> things[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> costA[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> costB[i];
    }

    for (int amountA = 0; amountA <= 1000000; amountA++) {
        int max_b = 1000000;
        bool works = true;
        for (int i = 0; i < n; i++) {
            if (things[i] - costA[i] * amountA < 0) works = false;
            if (costB[i] == 0) continue;
            max_b = min(max_b, (things[i] - costA[i] * amountA) / costB[i]);
            if (max_b < 0) works = false;
        }
        if (!works) break;
        ans = max(amountA + max_b, ans);
    }
    printf("%d\n",ans);
}