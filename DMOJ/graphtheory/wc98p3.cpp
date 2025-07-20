// KurbyDoo
// Feb 10th, 2024
// WC '98 P3 - Do or Do Not
// https://dmoj.ca/problem/wc98p3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int rows, cols;
int max_jump;
string grid[32010];

int bfs(int sx, int sy, int ex, int ey, int query_number)
{
    int visited[rows][cols] = {{0}};
    queue<pair<pii, int>> q;
    q.push({{sx, sy}, 0});
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cd = q.front().second;
        q.pop();
        // printf("at %d %d %d\n", cx, cy, cd);
        if (cx == ex && cy == ey)
            return cd;

        int jx = 0;
        int jy = 0;
        while (jx * jx + jy * jy <= max_jump) {
            while (jx * jx + jy * jy <= max_jump) {
                int nx = cx + jx, ny = cy + jy;
                if (0 <= nx && nx < cols && 0 <= ny && ny < rows && visited[ny][nx] != query_number && grid[ny][nx] == '*') {
                    visited[ny][nx] = query_number;
                    q.push({{nx, ny}, cd + 1});
                }
                nx = cx - jx, ny = cy + jy;
                if (0 <= nx && nx < cols && 0 <= ny && ny < rows && visited[ny][nx] != query_number && grid[ny][nx] == '*') {
                    visited[ny][nx] = query_number;
                    q.push({{nx, ny}, cd + 1});
                }
                nx = cx + jx, ny = cy - jy;
                if (0 <= nx && nx < cols && 0 <= ny && ny < rows && visited[ny][nx] != query_number && grid[ny][nx] == '*') {
                    visited[ny][nx] = query_number;
                    q.push({{nx, ny}, cd + 1});
                }
                nx = cx - jx, ny = cy - jy;
                if (0 <= nx && nx < cols && 0 <= ny && ny < rows && visited[ny][nx] != query_number && grid[ny][nx] == '*') {
                    visited[ny][nx] = query_number;
                    q.push({{nx, ny}, cd + 1});
                }
                jy += 1;
            }

            jy = 0;
            jx += 1;
        }
    }
    return 999999999;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> rows >> cols >> max_jump;
    max_jump = max_jump * max_jump;

    for (int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }

    int a, b, c, d;
    cin >> a;
    int i = 1;
    while (a != -1)
    {
        cin >> b >> c >> d;
        // printf("%d %d %d %d\n", a, b, c, d);
        int ans = bfs(b - 1, a - 1, d - 1, c - 1, i);
        if (ans == 999999999)
        {
            printf("THERE IS NO TRY\n");
        }
        else
        {
            printf("%d\n", ans);
        }
        i += 1;
        cin >> a;
    }

    return 0;
}
// 5
// 5
// 2
// oooo*
// ooo*o
// oo*o*
// ooo**
// *ooo*
// 5 5
// 1 5
// 5 1
// 1 5
// -1 -1