#include <bits/stdc++.h>
using namespace std;
int dp[51][51][51];
int t, n, q, s1, s2;
string a1, a2, a3;

int solve(int a, int b, int l)
{
    // printf("at %d %d %d v = %d\n", a, b, l, dp[a][b][l]);
    if (a < 0 || b < 0 || l < 0) return -1000000;
    if (a > l || b > l) return -1000000;
    if (dp[a][b][l] > 0) return dp[a][b][l];
    if (a == 0 && b == 0 && l == 0) return 0;
    int x = a1[l - 1] == 'T';
    int y = a2[l - 1] == 'T';
    int z = a3[l - 1] == 'T';
    dp[a][b][l] = max(solve(a + x - 1, b + y - 1, l - 1) - z + 1, solve(a - x, b - y, l - 1) + z);
    // printf("done %d %d %d v = %d\n", a, b, l, dp[a][b][l]);
    return dp[a][b][l];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        cin >> n >> q;
        cin >> a1;
        a2 = a1;
        if (n == 2)
            cin >> a2;
        cin >> a3;
        cin >> s1;
        s2 = s1;
        if (n == 2)
            cin >> s2;

        for (int c = 0; c <= q; c++)
        {
            for (int a = 0; a <= min(c, q); a++)
            {
                for (int b = 0; b <= min(c, q); b++)
                {
                    dp[a][b][c] = -100000;
                }
            }
        }

        dp[0][0][0] = 0;
        solve(s1, s2, q);
        // for (int x = 0; x <= q; x++) {
        //     printf("x = %d\n", x);
        //     for (int i = 0; i <= q; i++)
        //     {
        //         for (int j = 0; j <= q; j++)
        //         {
        //             printf("%d ", dp[i][j][x]);
        //         }
        //         printf("\n");
        //     }
        // }
        int ans = 0;
        for (int i = 0; i <= q; i++)
        {
            ans = max(ans, dp[s1][s2][i]);
        }
        printf("Case #%d: %d\n", _ + 1, ans);
    }
}