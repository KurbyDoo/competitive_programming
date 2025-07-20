// Kurbydoo
// May 27th, 2023
// CCC '23 J5 - CCC Word Hunt
// https://dmoj.ca/problem/ccc23j5
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using std::cin;
using std::max;
using std::memset;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

int R, C, target_length;
char grid[110][110];
string target;

int search(int x, int y, int cur_pos, int dir, bool turned)
{
    // printf("valid at %d %d %d\n", x, y, dir);
    int x_off[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int y_off[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    if (x < 0 || x >= C || y < 0 || y >= R)
        return 0;
    if (cur_pos == target_length) {
        // printf("completed\n");
        return 1;
    }

    int count = 0;
    if (grid[y + y_off[dir]][x + x_off[dir]] == target[cur_pos])
        count += search(x + x_off[dir], y + y_off[dir], cur_pos + 1, dir, turned);

    if (grid[y + y_off[(dir + 2) % 8]][x + x_off[(dir + 2) % 8]] == target[cur_pos] && !turned && cur_pos != 1)
        count += search(x + x_off[(dir + 2) % 8], y + y_off[(dir + 2) % 8], cur_pos + 1, (dir + 2) % 8, true);

    if (grid[y + y_off[(dir + 6) % 8]][x + x_off[(dir + 6) % 8]] == target[cur_pos] && !turned && cur_pos != 1)
        count += search(x + x_off[(dir + 6) % 8], y + y_off[(dir + 6) % 8], cur_pos + 1, (dir + 6) % 8, true);

    return count;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> target >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
        }
    }
    target_length = target.length();

    int count = 0;
    for (int x = 0; x < C; x++)
    {
        for (int y = 0; y < R; y++)
        {
            if (grid[y][x] != target[0])
                continue;

            for (int i = 0; i < 8; i++)
            {
                count += search(x, y, 1, i, false);
            }
        }
    }

    printf("%d\n", count);
    return 0;
}