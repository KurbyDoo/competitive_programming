#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, total;
ll t, d, last;
unordered_map<ll, int> counter;
multiset<ll> avail;
priority_queue<pll, vector<pll>, greater<pll>> pq;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> d;
        pq.push({t, t + d + 1});
        pq.push({t + d + 1, -1});
    }
    last = 1;
    while (!pq.empty())
    {
        // printf("time = %lld\n", last);
        while (!pq.empty() && pq.top().first <= last) {
            if (pq.top().second == -1) {
                if (counter[pq.top().first] > 0)
                {
                    counter[pq.top().first] -= 1;
                    if (counter[pq.top().first] == 0)
                    {
                        avail.erase(pq.top().first);
                    }
                }
            } else {
                // printf("size before = %d\n", avail.size());
                avail.insert(pq.top().second);
                counter[pq.top().second] += 1;
                // printf("adding %d size = %d\n", pq.top().second, avail.size());
            }
            pq.pop();
        }
        if (!avail.empty()) {
            // printf("taking %lld at %lld\n", *avail.begin(), last);
            last += 1;
            total += 1;
            if (counter[*avail.begin()] > 0) {
                counter[*avail.begin()] -= 1;
                if (counter[*avail.begin()] == 0) {
                    avail.erase(*avail.begin());
                }
            }
        } else {
            last = pq.top().first;
        }
        // printf("size = %d\n", pq.size());
    }
    printf("%d\n", total);
}
// 5
// 1 1
// 1 4
// 1 4
// 2 1
// 1 5
// 10
// 1 3
// 1 5
// 2 3
// 2 6
// 3 5
// 4 5
// 4 5
// 4 5
// 5 6
// 5 6