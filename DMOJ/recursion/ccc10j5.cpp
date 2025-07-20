#include <iostream>

using std::cin;
using std::min;

int a, b, c, d;
int visited[8][8];
void hop(int x, int y, int endX, int endY, int depth)
{
    // printf("(%d, %d)\n", x, y);
    visited[x][y] = depth;

    if (depth == 6)
        return;

    int xDir[] = {1, -1, 1, -1, 2, -2, 2, -2};
    int yDir[] = {2, 2, -2, -2, 1, 1, -1, -1};

    for (int i = 0; i < 8; i++)
    {
        if (x + xDir[i] < 8 && x + xDir[i] >= 0 && y + yDir[i] < 8 && y + yDir[i] >= 0)
        {
            if (depth + 1 < visited[x + xDir[i]][y + yDir[i]]) {
                hop(x + xDir[i], y + yDir[i], endX, endY, depth + 1);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> a >> b >> c >> d;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            visited[x][y] = 999;
        }
    }
    hop(a - 1, b - 1, c - 1, d - 1, 0);
    printf("%d\n", visited[c - 1][d - 1]);

    return 0;
}