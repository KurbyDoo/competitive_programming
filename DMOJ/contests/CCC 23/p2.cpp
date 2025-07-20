#include <iostream>

using std::cin;
using std::min;
using std::abs;

typedef long long ll;

int n;
int mount[5005];
int dp[5005][5005];

int evaluate(int l, int r) {
    if (l >= r) {
        return dp[l][r] = 0;
    }
    if (dp[l][r]) {
        return dp[l][r];
    }

    int score = abs(mount[l] - mount[r]) + evaluate(l + 1, r - 1);
    return dp[l][r] = score;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mount[i];
    }

    for (int size = 0; size < n; size++) {
        int b = INT32_MAX;
        for (int i = 0; i < n - size; i++)
        {
            b = min(b, evaluate(i, size + i));
        }
        printf("%d ", b);
    }
}

// 7
// 3 1 4 1 5 9 2 

// 4
// 1 3 5 6 