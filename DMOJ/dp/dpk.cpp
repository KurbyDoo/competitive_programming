#include <iostream>
#include <vector>

using std::cin;
using std::max;
using std::min;
using std::vector;

int n, k, a;
vector<int> options;
int dp[3][100005];

int findWinner(int player, int stonesUsed)
{
    if (dp[player + 1][stonesUsed])
        return dp[player + 1][stonesUsed];
   
    int best = player * -1;
    for (int o : options)
    {
        if ((stonesUsed - o) >= 0)
        {
            if (player == 1) best = max(findWinner(-1, stonesUsed - o), best);
            else best = min(findWinner(1, stonesUsed - o), best);
        }
    }

    return dp[player + 1][stonesUsed] = best;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        options.push_back(a);
    }

    if (findWinner(1, k) == 1)
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}