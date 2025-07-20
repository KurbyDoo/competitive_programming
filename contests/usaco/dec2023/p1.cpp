#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
deque<pii> q;
ll n, m, k, a, b, ans = 0;
vector<pii> cows;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cows.push_back({a, b});
    }
    sort(cows.begin(), cows.end());
    q.push_back({0, m});

    for (auto [wi, ai] : cows)
    {
        int amount = 0;
        while (amount < ai && !q.empty() && (q.front().first == 0 || q.front().first + k <= wi))
        {
            int cur_weight = q.front().first;
            int cur_size = q.front().second;
            // printf("front is %d %d\n", cur_weight, cur_size);
            q.pop_front();
            if (amount + cur_size > ai)
            {
                cur_size -= ai - amount;
                amount = ai;
                // printf("adding back %d %d\n", cur_size, cur_weight);
                q.push_front({cur_weight, cur_size});
            }
            else if (amount + cur_size <= ai)
            {
                amount += cur_size;
            }
        }
        // printf("using %d of %d\n", amount, wi);
        q.push_back({wi, amount});
        ans += amount;
    }
    printf("%lld\n", ans);

    return 0;
}
// 3 100 3
// 4 100
// 2 50
// 1 50