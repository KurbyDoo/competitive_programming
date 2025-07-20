#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int rows[2010];
int cols[2010];
int diagonal[2];

int n, t, ai;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> ai;
        rows[(ai - 1) / n] += 1;
        cols[(ai - 1) % n] += 1;
        if ((ai - 1) / n == (ai - 1) % n)
        {
            diagonal[0] += 1;
        }
        if ((ai - 1) / n == n - ((ai - 1) % n) - 1)
        {
            diagonal[1] += 1;
        }

        // printf("%d %d\n", (ai - 1) / n, (ai - 1) % n);
        // printf("%d %d %d %d\n", rows[(ai - 1) / n], cols[(ai - 1) % n], diagonal[0], diagonal[1]);
        if (rows[(ai - 1) / n] == n || cols[(ai - 1) % n] == n || diagonal[0] == n || diagonal[1] == n)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}