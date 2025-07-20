#include <bits/stdc++.h>
using namespace std;
int n, m;
queue<int> q;
set<int> parking;
unordered_map<int, int> in_spot;
int ans = 0;
int rates[110];
int weights[2010];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> rates[i];
        parking.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0, car; i < m * 2; i++)
    {
        cin >> car;
        if (car > 0)
        {
            if (parking.empty())
            {
                q.push(car);
            }
            else
            {
                ans += rates[*parking.begin()] * weights[car];
                in_spot[car] = *parking.begin();
                parking.erase(parking.begin());
            }
        }
        else
        {
            car = car * -1;
            if (!q.empty())
            {
                ans += rates[in_spot[car]] * weights[q.front()];
                in_spot[q.front()] = in_spot[car];
                q.pop();
            }
            else
            {
                parking.insert(in_spot[car]);
            }
        }
    }
    printf("%d\n", ans);
}