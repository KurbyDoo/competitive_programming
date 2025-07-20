#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll rows = 0;
ll cols = 0;
int uniquePaint = 0;
bool rowsPainted[200010];
bool colsPainted[200010];
ll paintAmount[200010];
deque<array<ll, 3>> ops;
ll h, w, m;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> h >> w >> m;
    for (ll i = 0, t, a, x; i < m; i++)
    {
        cin >> t >> a >> x;
        ops.push_front({t, a, x});
    }
    paintAmount[0] = h * w;
    for (int i = 0; i < m; i++)
    {
        ll curT = ops.front().at(0);
        ll curA = ops.front().at(1);
        ll curX = ops.front().at(2);
        ops.pop_front();

        if (curT == 1)
        {
            if (rowsPainted[curA]) continue;
            rows += 1;
            rowsPainted[curA] = true;
            if (curX == 0) continue;
            paintAmount[curX] += w - cols;
            paintAmount[0] -= w - cols;
        }
        else
        {
            if (colsPainted[curA]) continue;
            cols += 1;
            colsPainted[curA] = true;
            if (curX == 0) continue;
            paintAmount[curX] += h - rows;
            paintAmount[0] -= h - rows;
        }
    }

    
    for (int i = 0; i <= 200000; i++)
    {
        if (paintAmount[i] > 0)
            uniquePaint += 1;
    }
    printf("%d\n", uniquePaint);
    for (int i = 0; i <= 200000; i++)
    {
        if (paintAmount[i] > 0)
            printf("%d %lld\n", i, paintAmount[i]);
    }
    return 0;
}