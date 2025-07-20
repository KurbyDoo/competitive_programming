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

bool grid[1005][1005];

int n, m, k, a, b, count = 0;

void checkSeat(int x, int y)
{
    if (grid[x][y])
        return;

    int adj = 0;
    // printf("checking %d, %d\n", x, y);
    if (x + 1 < m)
        if (grid[x + 1][y]) {
            adj++;
            // printf("right");
        }

    if (x - 1 >= 0)
        if (grid[x - 1][y]) {
            adj++;
            // printf("left");
        }

    if (y + 1 < n)
        if (grid[x][y + 1])
            adj++;

    if (y - 1 >= 0)
        if (grid[x][y - 1])
            adj++;



    if (x + 1 < m && y + 1 < n)
        if (grid[x + 1][y + 1])
            adj++;

    if (x - 1 >= 0 && y - 1 >= 0)
        if (grid[x - 1][y - 1])
            adj++;

    if (y + 1 < n && x - 1 >= 0)
        if (grid[x - 1][y + 1])
            adj++;

    if (y - 1 >= 0 && x + 1 < m)
        if (grid[x + 1][y - 1])
            adj++;

    // printf("adj = %d\n", adj);
    if (adj >= 3)
        count++;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        grid[b - 1][a - 1] = true;
    }

    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            checkSeat(x, y);
        }
    }

    printf("%d\n", count);
    return 0;
}