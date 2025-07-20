#include <bits/stdc++.h>
using namespace std;
string n, m;
map<int, int> cnt[110];
map<string, bool> found;
int iters = 1;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;

    // printf("%d: %s\n", iters, n.c_str());
    if (n == m) {
        printf("1\n");
        return 0;
    }
    while (iters <= 100) {
        iters++;
        if (iters > 100) break;
        for (int i = 0; i < n.length(); i++) {
            cnt[iters][n[i] - '0']++;
        }
        n = "";
        for (int i = 0; i < 10; i++) {
            if (cnt[iters][i] == 0) continue;
            n += to_string(cnt[iters][i]) + to_string(i);
        }
        // printf("%d: %s\n", iters, n.c_str());
        if (found[n]) {
            break;
        }

        found[n] = true;
        if (n == m) break;

    }
    if (found[m]) {
        printf("%d\n", iters);
    } else if (iters <= 100) {
        printf("Does not appear\n");
    } else {
        printf("I'm bored\n");

    }
    return 0;
}