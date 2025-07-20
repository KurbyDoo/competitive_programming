#include <iostream>
#include <array>

using std::cin;
using std::max;
using std::copy;
using std::array;

typedef array<int, 4> a;
typedef array<a, 4> aa;

aa grid = {{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
}};
int maxValue = 0;

aa copyGrid(aa oldGrid)
{
    aa newGrid = {{
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }};

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            newGrid[x][y] = oldGrid[x][y];
        }
    }
    return newGrid;
}

void printGrid(aa grid, int moveNum)
{
    printf("----- Move Number %d -----\n", moveNum);
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            printf("%d-", grid[x][y]);
        }
        printf("\n");
    }
}

aa moveLeft(aa oldGrid)
{
    aa newGrid = copyGrid(oldGrid);

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            maxValue = max(newGrid[x][y], maxValue);
            if (newGrid[x][y] == newGrid[x + 1][y])
            {
                newGrid[x][y] = newGrid[x][y] + newGrid[x + 1][y];
                newGrid[x + 1][y] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (newGrid[x][y] == 0)
                {
                    newGrid[x][y] = newGrid[x + 1][y];
                    newGrid[x + 1][y] = 0;
                }
            }
        }
    }
    return newGrid;
}

aa moveRight(aa oldGrid)
{
    aa newGrid = copyGrid(oldGrid);

    for (int x = 3; x > 0; x--)
    {
        for (int y = 0; y < 4; y++)
        {
            maxValue = max(newGrid[x][y], maxValue);
            if (newGrid[x][y] == newGrid[x - 1][y])
            {
                newGrid[x][y] = newGrid[x][y] + newGrid[x - 1][y];
                newGrid[x - 1][y] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int x = 3; x > 0; x--)
        {
            for (int y = 0; y < 4; y++)
            {
                if (!newGrid[x][y])
                {
                    newGrid[x][y] = newGrid[x - 1][y];
                    newGrid[x - 1][y] = 0;
                }
            }
        }
    }
    return newGrid;
}

aa moveUp(aa oldGrid)
{
    aa newGrid = copyGrid(oldGrid);

    for (int y = 3; y > 0; y--)
    {
        for (int x = 0; x < 4; x++)
        {
            maxValue = max(newGrid[x][y], maxValue);
            if (newGrid[x][y] == newGrid[x][y - 1])
            {
                newGrid[x][y] = newGrid[x][y] + newGrid[x][y - 1];
                newGrid[x][y - 1] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int y = 3; y > 0; y--)
        {
            for (int x = 0; x < 4; x++)
            {
                if (!newGrid[x][y])
                {
                    newGrid[x][y] = newGrid[x][y - 1];
                    newGrid[x][y - 1] = 0;
                }
            }
        }
    }
    return newGrid;
}

aa moveDown(aa oldGrid)
{
    aa newGrid = copyGrid(oldGrid);

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            maxValue = max(newGrid[x][y], maxValue);
            if (newGrid[x][y] == newGrid[x][y + 1])
            {
                newGrid[x][y] = newGrid[x][y] + newGrid[x][y + 1];
                newGrid[x][y + 1] = 0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (newGrid[x][y] == 0)
                {
                    newGrid[x][y] = newGrid[x][y + 1];
                    newGrid[x][y + 1] = 0;
                }
            }
        }
    }
    return newGrid;
}

void solve(aa oldGrid, int moveNumber, int pastMove)
{
    if (moveNumber > 14) return;
    if (maxValue == 2048) return;
    // if (moveNumber % 2 == 0)
    // {
    if (pastMove != 1)
    {
        aa left = moveLeft(oldGrid);
        if (left != oldGrid)
        {
            // printGrid(left, moveNumber);
            solve(left, moveNumber + 1, 1);
        }
    }

    if (pastMove != 2)
    {
        aa right = moveRight(oldGrid);
        if (right != oldGrid)
        {
            // printGrid(right, moveNumber);
            solve(right, moveNumber + 1, 2);
        }
    }

    if (pastMove != 3)
    {
        aa up = moveUp(oldGrid);
        if (up != oldGrid)
        {
            // printGrid(up, moveNumber);
            solve(up, moveNumber + 1, 3);
        }
    }

    if (pastMove != 4)
    {
        aa down = moveDown(oldGrid);
        if (down != oldGrid)
        {
            // printGrid(down, moveNumber);
            solve(down, moveNumber + 1, 4);
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) cin >> grid[j][i];
        
        maxValue = 0;
        solve(grid, 1, -1);
        // printf("max num = %d\n", maxValue);
        printf("%d\n", maxValue);
        // solve();
        
    }
    return 0;
}
// 2 2 4 8
// 128 64 32 16
// 256 512 1024 2
// 2 2 2 2
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 2 0 0 0
// 0 2 0 0
// 0 0 2 0
// 0 0 0 2
