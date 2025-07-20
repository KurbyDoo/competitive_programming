// Kurbydoo
// April 9th, 2023
// DWITE '06 R5 #2 - Floppy Disk
// https://dmoj.ca/problem/dwite06c5p2
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cin;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

bool dp[1441];
int sizes[30];
int n;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int _ = 0; _ < 5; _++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> sizes[i];
        }
        for (int i = 0; i <= 1440; i++) {
            dp[i] = false;
        }
        dp[0] = true;
        for (int j = 0; j < n; j++)
        {
            for (int i = 1440 - sizes[j]; i >= 0; i--)
            {
                if (dp[i])
                {
                    dp[i + sizes[j]] = true;
                }
            }
        }

        for (int i = 1440; i >= 0; i--) {
            if (dp[i]) {
                printf("%d\n", 1440 - i);
                break;
            }
        }
    }

        return 0;
}