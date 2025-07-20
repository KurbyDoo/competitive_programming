// Kurbydoo
// Feb 25th, 2023
// CCC '02 S4 - Bridge Crossing
// https://dmoj.ca/problem/ccc02s4
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

string names[105];
int t[105];
int dp[105];
vector<vector<string>> best[105];

int m, q;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> m >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> names[i];
        cin >> t[i];
        dp[i + 1] = INT32_MAX;
    }

    dp[0] = 0;
    for (int i = 1; i <= q; i++)
    {
        int maxScore = 0;
        vector<string> nam;
        for (int j = 1; j <= min(m, i); j++)
        {
            nam.push_back(names[i - j]);
            maxScore = max(maxScore, t[i - j]);
            if (dp[i - j] + maxScore < dp[i])
            {
                dp[i] = dp[i - j] + maxScore;
                best[i] = best[i - j];
                best[i].push_back(nam);
            }
        }
    }

    printf("Total Time: %d\n", dp[q]);
    for (vector<string> e : best[q])
    {
        for (string a : e)
        {
            printf("%s ", a.c_str());
        }
        printf("\n");
    }
    return 0;
}

// 10
// 5
// alice
// 1
// bob
// 5
// charlie
// 5
// dobson
// 3
// eric
// 3