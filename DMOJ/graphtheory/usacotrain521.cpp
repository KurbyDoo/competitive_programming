// Kurbydoo
// Month Day, 2023
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;
using std::max;

int n, b;
bool blocks[200][200];
bool visited[200][200];
char x;
int y;

int maxDist = 0;

void search(int x, int y, int dist, int direction) {
    // printf("at %d %d d = %d\n", x, y, direction);
    if (blocks[x][y]) return;
    // if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
    //     // printf("out");
    //     return;
    // }

    if (visited[x][y]) {
        // printf("vis");
        return;
    }
    
    // 0 = y+, 1 = x+, 2 = y-, 3 = x-
    int xOff[] = {0, 1, 0, -1};
    int yOff[] = {1, 0, -1, 0};
    visited[x][y] = true;

    maxDist = max(maxDist, dist);
    if (blocks[x + xOff[direction % 4]][y + yOff[direction % 4]]) {
        search(x + xOff[(direction + 1) % 4], y + yOff[(direction + 1) % 4], dist + 1, direction + 1);
        search(x + xOff[(direction - 1) % 4], y + yOff[(direction - 1) % 4], dist + 1, direction - 1);
    } else {
        search(x + xOff[direction % 4], y + yOff[direction % 4], dist + 1, direction);
    }
    visited[x][y] = false;
    return;

}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> b;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1) {
                blocks[i][j] = true;
            }
        } 
    }
    for (int i = 0 ; i < b; i++) {
        cin >> x >> y;

        blocks[x - 'A' + 1][y] = true;
        // printf("%d %d\n", x - 'A', y);
    }

    search(1, 1, 1, 12001);
    search(1, 1, 1, 12000);

    printf("%d\n", maxDist);


    
    return 0;
}