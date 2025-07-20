#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tt;
string grid[1010];
int dist[1010][1010];
priority_queue<tt, vector<tt>, greater<tt>> pq;
int H, W, A, B, C, D;

bool check(int x1, int y1, int x2, int y2) {
    return !(x2 < 1 || x2 > W || y2 < 1 || y2 > H);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> H >> W;
    for (int i = 0; i < H; i++){
        string s;
        cin >> s;
        grid[i + 1] = "#" + s;
        for (int j = 0; j < W; j++){
            dist[i + 1][j + 1] = 99999999;
        }
    }
    cin >> A >> B >> C >> D;

    dist[A][B] = 0;
    pq.push({0, B, A});
    while (!pq.empty()) {
        int x, y, d;
        tie(d, x, y) = pq.top();
        pq.pop();
        d = dist[y][x];
        // printf("at %d %d %d %d\n", x, y, d, dist[y][x]);

        if (check(x, y, x + 1, y)) {
            if (grid[y][x + 1] == '#') {
                if (dist[y][x + 1] > dist[y][x] + 1) {
                    dist[y][x + 1] = dist[y][x] + 1;
                    pq.push({dist[y][x + 1], x + 1, y});
                }
                if (check(x, y, x + 2, y) && dist[y][x + 2] > dist[y][x] + 1) {
                    dist[y][x + 2] = dist[y][x] + 1;
                    pq.push({dist[y][x + 2], x + 2, y});
                }
            } else {
                if (dist[y][x + 1] > dist[y][x]) {
                    dist[y][x + 1] = dist[y][x];
                    pq.push({dist[y][x + 1], x + 1, y});
                }
            }
        }
        if (check(x, y, x - 1, y)) {
            if (grid[y][x - 1] == '#') {
                if (dist[y][x - 1] > dist[y][x] + 1) {
                    dist[y][x - 1] = dist[y][x] + 1;
                    pq.push({dist[y][x - 1], x - 1, y});
                }
                if (check(x, y, x - 2, y) && dist[y][x - 2] > dist[y][x] + 1) {
                    dist[y][x - 2] = dist[y][x] + 1;
                    pq.push({dist[y][x - 2], x - 2, y});
                }
            } else {
                if (dist[y][x - 1] > dist[y][x]) {
                    dist[y][x - 1] = dist[y][x];
                    pq.push({dist[y][x - 1], x - 1, y});
                }
            }
        }
        if (check(x, y, x, y - 1)) {
            if (grid[y - 1][x] == '#') {
                if (dist[y - 1][x] > dist[y][x] + 1) {
                    dist[y - 1][x] = dist[y][x] + 1;
                    pq.push({dist[y - 1][x], x, y - 1});
                }
                if (check(x, y, x, y - 2) && dist[y - 2][x] > dist[y][x] + 1) {
                    dist[y - 2][x] = dist[y][x] + 1;
                    pq.push({dist[y - 2][x], x, y - 2});
                }
            } else {
                if (dist[y - 1][x] > dist[y][x]) {
                    dist[y - 1][x] = dist[y][x];
                    pq.push({dist[y - 1][x], x, y - 1});
                }
            }
        }
        if (check(x, y, x, y + 1)) {
            if (grid[y + 1][x] == '#') {
                if (dist[y + 1][x] > dist[y][x] + 1) {
                    dist[y + 1][x] = dist[y][x] + 1;
                    pq.push({dist[y + 1][x], x, y + 1});
                }
                if (check(x, y, x, y + 2) && dist[y + 2][x] > dist[y][x] + 1) {
                    dist[y + 2][x] = dist[y][x] + 1;
                    pq.push({dist[y + 2][x], x, y + 2});
                }
            } else {
                if (dist[y + 1][x] > dist[y][x]) {
                    dist[y + 1][x] = dist[y][x];
                    pq.push({dist[y + 1][x], x, y + 1});
                }
            }
        }
    }
    // for (int i = 1; i <= H; i++){
    //     for (int j = 1; j <= W; j++){
    //         printf("%d ", dist[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("ans = %d %d %d\n", dist[C][D], D, C);
    printf("%d\n", dist[C][D]);

    return 0;
}