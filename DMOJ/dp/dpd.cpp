// Nov 26th, 2022

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
#include <algorithm>
#include <utility>
#include <queue>

using std::abs;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;

ll dp[int(1e5 + 5)] = {0};
vector<pair<int, int>> weights;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, maxWeight;
    cin >> n >> maxWeight;

    int w, v;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        weights.push_back({w, v});
    }

    for (int i = 0; i < n; i++)
    {
        // for (int j = 0; j < maxWeight; j++)
        for (int j = maxWeight; j >= 0; j--) // Go backwards so items value does not trip on itself (overlap)
        {
            // printf("checking %d at weight %d\n", weights[i].second, j);
            if (j + weights[i].first <= maxWeight)
                dp[j + weights[i].first] = max(dp[j + weights[i].first], dp[j] + weights[i].second);
        }
    }

    ll maxValue = 0;

    for (auto a: dp)
        maxValue = max(maxValue, a);
    printf("%llu\n", maxValue);
    return 0;
}