#include <bits/stdc++.h>

using std::cin;
using std::max;
using std::min;
using std::vector;
typedef long long ll;
struct item
{
    ll c;
    int k[6];
};

int n, k, p;
vector<item> items;
ll dp[6][6][6][6][6];

int main()
{
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++)
    {
        item new_item;
        cin >> new_item.c;
        // printf("c = %d\n", new_item.c);
        for (int j = 0; j < k; j++)
        {
            cin >> new_item.k[j];
            // printf("k = %d %d\n", new_item.k[j], j);
        }
        for (int j = k; j < 5; j++)
        {
            new_item.k[j] = p;
        }
        items.push_back(new_item);
        // printf("size = %d\n", items.size());
    }
    // printf("input done");

    for (int a = 0; a <= p; a++)
    {
        for (int b = 0; b <= p; b++)
        {
            for (int c = 0; c <= p; c++)
            {
                for (int d = 0; d <= p; d++)
                {
                    for (int e = 0; e <= p; e++)
                    {
                        dp[a][b][c][d][e] = 1e12;
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int a = p; a >= 0; a--)
        {
            for (int b = p; b >= 0; b--)
            {
                for (int c = p; c >= 0; c--)
                {
                    for (int d = p; d >= 0; d--)
                    {
                        for (int e = p; e >= 0; e--)
                        {
                            if (i > items.size())
                                continue;
                            // printf("%d %d %d %d %d %d\n", i, a, b, c, d, e);
                            // printf("%d %d %d %d %d %d\n", items[i].c, items[i].k[0], items[i].k[1], items[i].k[2], items[i].k[3], items[i].k[4]);
                            // if (dp[i][a][b][c][d][e] < dp[i - 1][max(0, a - items[i].k[0])][max(0, b - items[i].k[1])][max(0, c - items[i].k[2])][max(0, d - items[i].k[3])][max(0, e - items[i].k[4])] + items[i].c) {
                            //     dp[i][a][b][c][d][e] = dp[i - 1][max(0, a - items[i].k[0])][max(0, b - items[i].k[1])][max(0, c - items[i].k[2])][max(0, d - items[i].k[3])][max(0, e - items[i].k[4])] + items[i].c;
                            // }
                            if (dp[min(p, a + items[i].k[0])][min(p, b + items[i].k[1])][min(p, c + items[i].k[2])][min(p, d + items[i].k[3])][min(p, e + items[i].k[4])] > dp[a][b][c][d][e] + items[i].c)
                            {
                                // printf("updated at %d %d %d %d %d %d\n", i, a, b, c, d, e);
                                dp[min(p, a + items[i].k[0])][min(p, b + items[i].k[1])][min(p, c + items[i].k[2])][min(p, d + items[i].k[3])][min(p, e + items[i].k[4])] = dp[a][b][c][d][e] + items[i].c;
                            }
                        }
                    }
                }
            }
        }
    }
    ll min_cost = 1e12;
    for (int i = 0; i <= n; i++)
    {
        if (dp[p][p][p][p][p] < min_cost)
            min_cost = dp[p][p][p][p][p];
    }
    printf("%lld\n", min_cost == 1e12 ? -1 : min_cost);
    return 0;
}