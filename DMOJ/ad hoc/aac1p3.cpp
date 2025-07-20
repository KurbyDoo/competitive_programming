#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    if (n % 2 != k % 2)
    {
        printf("-1\n");
    }
    else if (n == k)
    {
        for (int i = 1; i < k; i++)
        {
            printf("2 ");
        }
        printf("2\n");
    }
    else
    {
        for (int i = 0; i <= k; i++)
        {
            printf("2 ");
        }
        for (int i = 1; i < n - k - 1; i++)
        {
            printf(i % 2 == 1 ? "1 " : "2 ");
        }
        printf("1\n");
    }
}

// even size
// even happy
// 8 6
// 1 2 2 2 2 2 2 2
// 8 4
// 1 2 2 2 2 2 1 2
// Even odd impossible
// 8 5
// 1 2 2 2 2 1 2 2

// odd size
// odd happy
// 7 3
// 2 2 2 2 1 2 1
// even happy impossible
// 7 2
// 1 2 2 2 1 2 1
