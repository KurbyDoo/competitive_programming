// Kurbydoo
// Feb 22, 2023
// COCI '09 Contest 2 #3 Kutevi
// https://dmoj.ca/problem/coci09c2p3
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;

int n, k;
int a, b;
bool dp[400];
int angles[15];

void fill(int angle) {
    // printf("at %d\n", angle);
    if (angle < 0) {
        angle = (3600 + angle) % 360;
    }

    if (dp[angle]) {
        return;
    }

    dp[angle] = true;
    for (int i = 0; i < n; i++) {
        fill(angle - angles[i]);
        fill(angle - angles[i]);
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i <= 360; i++) {
        dp[i] = false;
    }
    for (int i = 0; i < n; i++) {
        cin >> angles[i];
    }

    fill(0);

    for (int i = 0; i < k; i++) {
        cin >> a;
        printf(dp[a] ? "YES" : "NO");
        printf("\n");
    }
    
    
    return 0;
}