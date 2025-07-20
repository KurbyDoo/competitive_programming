#include <bits/stdc++.h>
using namespace std;
int n, m, p;
bool solved[2010][2010];
int points[2010];
vector<array<int, 3>> scores;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++)
    {
        points[i] = n;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> solved[i][j];
            if (solved[i][j])
            {
                points[j] -= 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int cur_score = 0;
        int num_solved = 0;
        for (int j = 0; j < m; j++)
        {
            if (solved[i][j])
            {
                cur_score += points[j];
                num_solved += 1;
            }
        }
        scores.push_back({cur_score, num_solved, n - i});
    }
    sort(scores.begin(), scores.end(), greater<array<int, 3>>());
    int placement = 1;
    for (auto [a, b, c] : scores)
    {
        // printf("%d %d %d\n", a, b, c);
        if (n - c + 1 == p)
        {
            printf("%d %d\n", a, placement);
        }
        placement += 1;
    }
}
