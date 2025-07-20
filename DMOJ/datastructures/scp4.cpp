#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxsize = 2005;
ll bit[2010][2010];
ll bit2[2010][2010];
ll grid[2010][2010];
int n, m, q;
void update(int i, int j, int v)
{
    for (int x = i; x <= maxsize; x += x & -x)
    {
        for (int y = j + (x - i); y <= maxsize; y += y & -y)
        {
            // printf("at %d %d\n", x, y);
            bit[x][y] += v;
        }
    }
}
ll query(int i, int j)
{
    ll total = 0;
    for (int x = i; x > 0; x -= x & -x)
    {
        for (int y = j + (x - i); y > 0; y -= y & -y)
        {
            // printf("at %d %d\n", x, y);
            total += bit[x][y];
        }
    }
    // printf("total for %d %d = %lld\n", i, j, total);
    return total;
}
void update2(int i, int j, int v)
{
    for (int x = i; x <= maxsize; x += x & -x)
    {
        for (int y = j; y <= maxsize; y += y & -y)
        {
            bit2[x][y] += v;
        }
    }
}
ll query2(int i, int j)
{
    ll total = 0;
    for (int x = i; x > 0; x -= x & -x)
    {
        for (int y = j; y > 0; y -= y & -y)
        {
            total += bit2[x][y];
        }
    }
    // printf("rect %d %d = %lld\n", i, j, total);
    return total;
}
ll query_rect(int x1, int y1, int x2, int y2)
{
    return query2(x1, y1) - query2(x1, y2 - 1) - query2(x2 - 1, y1) + query2(x2 - 1, y2 - 1);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int y = n; y > 0; y--)
    {
        for (int x = m; x > 0; x--)
        {
            cin >> grid[x][y];
            update(x, y, grid[x][y]);
            update2(x, y, grid[x][y]);
            // printf("(%d %d %d) ---------\n", x, y, grid[x][y]);
            // for (int y = n; y > 0; y--)
            // {
            //     for (int x = m; x > 0; x--)
            //     {
            //         printf("%d ", bit[x][y]);
            //     }
            //     printf("\n");
            // }
        }
    }
    for (int i = 0, a, b, c, d; i < q; i++)
    {
        cin >> a >> b >> c >> d;
        b = n - b + 1;
        c = m - c + 1;
        if (a == 1)
        {

            update(c, b, d - grid[c][b]);
            update2(c, b, d - grid[c][b]);
            // for (int y = n; y > 0; y--)
            // {
            //     for (int x = m; x > 0; x--)
            //     {
            //         printf("%d ", bit[x][y]);
            //     }
            //     printf("\n");
            // }
            grid[c][b] = d;
        }
        else
        {
            // printf("x = %d y = %d h = %d\n", c, b, d);
            ll ans = query(c, b + d - 1);
            if (b > 1)
            {
                // printf("sub rect (%d %d) (%d %d)\n", c, b - 1, c - d + 1, 1);
                ans -= query_rect(c, b - 1, c - d + 1, 1);
                if (c > d)
                {
                    // printf("sub %d %d\n", c - d, b - 1);
                    ans -= query(c - d, b - 1);
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
