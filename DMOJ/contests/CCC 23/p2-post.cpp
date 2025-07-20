#include <iostream>

using std::abs;
using std::cin;
using std::min;

typedef long long ll;

int n;
int mount[5005];
int dp[5005][5005];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mount[i];
    }

    for (int size = 0; size < n; size++)
    {
        int b = INT32_MAX;
        for (int i = 0; i < n - size; i++)
        {
            if (size == 0) {
                dp[i][i] = 0;
                b = 0;
            }
            else if (size == 1) {
                dp[i][i + size] = abs(mount[i] - mount[i + size]);
            }
            else {
                dp[i][i + size] = abs(mount[i] - mount[i + size]) + dp[i + 1][i + size - 1];
            }

            b = min(b, dp[i][i + size]);
        }

        printf("%d ", b);
    }
}

// 7
// 3 1 4 1 5 9 2

// 4
// 1 3 5 6