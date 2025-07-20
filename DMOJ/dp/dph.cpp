#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;

char grid[1005][1005];
int array[1005][1005] = {0};

int main()
{
    int h, w;
    cin >> h >> w;

    for (int y = 0; y < h; y++)
    {
        string row = "";
        cin >> row;
        for (int x = 0; x < w; x++)
        {
            grid[x][y] = row[x];
        }
    }
    array[0][0] = 1;
    for (int y = 0; y < h; y++)
    {
        if (grid[0][y + 1] == '#') break;
        array[0][y + 1] = array[0][y];
    }
    for (int x = 0; x < w; x++)
    {
        if (grid[x + 1][0] == '#') break;
        array[x + 1][0] = array[x][0];
    }

    for (int y = 1; y < h; y++)
    {
        for (int x = 1; x < w; x++)
        {
            // printf("Checking square [%d][%d]\n", x, y);
            if (grid[x][y] == '#') continue;
            else array[x][y] = (array[x - 1][y] + array[x][y - 1]) % 1000000007;
        }
    }
    // for (int y = 0; y < h; y++)
    // {
    //     for (int x = 0; x < w; x++)
    //     {
    //         cout << array[x][y] << " ";
    //     }
    //     cout << "\n";
    // }
    printf("%d\n", array[w - 1][h - 1]);
    return 0;
}