#include <iostream>

using std::cin;
using std::min;
using std::abs;

int n;
int best[5005];
int mount[5005];

int evaluate(int l, int r) {
    int score = 0;
    for (int i = 0; i <= (r - l) / 2; i++) {
        score += abs(mount[l + i] - mount[r - i]);
        // printf("%d %d = %d\n", l + i, r - i, abs(mount[l + i] - mount[r - i]));

    }

    // printf("score for %d %d is %d\n", l, r, score);
    return score;
}

void tryCrop(int size) {
    int b = 100000000;
    for (int i = 0; i <= n - size; i++) {
        b = min(b, evaluate(i, size - 1 + i));
    }

    // printf("best at size %d is %d\n", size, b);
    best[size] = b;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mount[i];
    }

    for (int i = 1; i <= n; i++) {
        tryCrop(i);
    }

    for (int i = 1; i < n; i++) {
        printf("%d ", best[i]);
    }
    printf("%d\n", best[n]);
}