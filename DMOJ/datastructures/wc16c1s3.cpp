#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::greater;
using std::max;
using std::pair;
using std::priority_queue;
using std::queue;
using std::sort;
using std::vector;

typedef long long ll;

// vector<pair<int, int>> street;
vector<pair<ll, int>> houses;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, t;
    cin >> n >> m >> t;

    int v;
    ll d;

    for (int i = 0; i < n; i++)
    {
        cin >> d >> v;
        houses.push_back({d, v});
    }

    sort(houses.begin(), houses.end());

    int nHouses;
    ll maxSum = 0, curSum = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // reverse pq
    queue<int> popped;
    for (int i = 0; i < n; i++)
    {
        nHouses = (m - (houses[i].first * 2)) / t;
        if (nHouses <= 0)
            break;
        // printf("n house at house %d = %d\n", i, nHouses);
        pq.push(houses[i].second);
        curSum += houses[i].second;
        // printf("here\n");
        
        while (pq.size() > nHouses)
        {
            curSum -= pq.top();
            pq.pop();
        }

        maxSum = max(curSum, maxSum);
    }

    printf("%llu\n", maxSum);
    return 0;
}