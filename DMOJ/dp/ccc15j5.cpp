#include <iostream>
#include <vector>

using std::cin;
using std::vector;

int dp[251][251][251];
int n, k;

// int givePie(int lastUsed, int piesUsed, int peopleGiven, vector<int> &order)
int givePie(int lastUsed, int piesUsed, int peopleGiven)
{
    if (piesUsed > n || peopleGiven > k)
    {
        // printf("no works");
        // for (int i : order)
        //     printf(" %d", i);

        // printf("\n");
        return 0;
    }

    if (dp[piesUsed][peopleGiven][lastUsed])
        return dp[piesUsed][peopleGiven][lastUsed];

    if (piesUsed == n && peopleGiven == k)
    {
        // printf("works");
        // for (int i : order)
        //     printf(" %d", i);

        // printf("\n");
        return 1;
    }

    int total = 0;
    // printf("limits are %d - %d\n", lastUsed, (((n - piesUsed) / k) + 1));
    for (int i = lastUsed; i <= (((n - piesUsed) / ((k - peopleGiven) > 0 ? (k - peopleGiven) : 1)) + 1); i++)
    {
        // printf("%d pies given to person %d\n", i, peopleGiven + 1);
        // order.push_back(i);
        // total += givePie(i, piesUsed + i, peopleGiven + 1, order);
        // order.pop_back();

        total += givePie(i, piesUsed + i, peopleGiven + 1);
    }
    // printf("total = %d\n", total);
    dp[piesUsed][peopleGiven][lastUsed] = total;
    return total;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    // dp[0][0] = 1;

    vector<int> order;
    // int total = givePie(1, 0, 0, order);
    int total = givePie(1, 0, 0);
    printf("%d\n", total);

    // for (int i = n; i >= 0; i--)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
}