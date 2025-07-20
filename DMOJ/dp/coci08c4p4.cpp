// KurbyDoo
// September 20th, 2024
// COCI '08 Contest 4 #4 Slikar
// https://dmoj.ca/problem/coci08c4p4
#include <iostream>
using namespace std;
const int MAXSIZE = (1 << 9) + 10;

int n, p;
string row;
int black_count[9][MAXSIZE][MAXSIZE];
int dp[9][MAXSIZE][MAXSIZE];
short past[9][MAXSIZE][MAXSIZE];
char output[MAXSIZE][MAXSIZE];
int count_black(int sz, int x, int y)
{
    if (sz == 0) {
        black_count[sz][x][y] = output[x][y] == '1';
        return black_count[sz][x][y];
    }

    black_count[sz][x][y] = 0;
    black_count[sz][x][y] += count_black(sz - 1, x * 2, y * 2);
    black_count[sz][x][y] += count_black(sz - 1, x * 2 + 1, y * 2);
    black_count[sz][x][y] += count_black(sz - 1, x * 2, y * 2 + 1);
    black_count[sz][x][y] += count_black(sz - 1, x * 2 + 1, y * 2 + 1);

    return black_count[sz][x][y];
}

int search(int sz, int x, int y) {
    if (sz == 0) {
        return 0;
    } 
    if (dp[sz][x][y]) return dp[sz][x][y];
    int best_ans = 1 << 18;
    int ans = 0;
    int square = (1 << (sz - 1)) * (1 << (sz - 1));
    int tl = search(sz - 1, x * 2, y * 2);
    int tr = search(sz - 1, x * 2 + 1, y * 2);
    int br = search(sz - 1, x * 2 + 1, y * 2 + 1);
    int bl = search(sz - 1, x * 2, y * 2 + 1);
    // topleft black
    ans = square - black_count[sz - 1][x * 2][y * 2];
    ans += black_count[sz - 1][x * 2 + 1][y * 2];
    ans += bl + br;
    if (ans < best_ans) {
        past[sz][x][y] = 10;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2][y * 2];
    ans += black_count[sz - 1][x * 2 + 1][y * 2 + 1];
    ans += tr + bl;
    if (ans < best_ans) {
        past[sz][x][y] = 11;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2][y * 2];
    ans += black_count[sz - 1][x * 2][y * 2 + 1];
    ans += tr + br;
    if (ans < best_ans) {
        past[sz][x][y] = 12;
        best_ans = ans;
    }

    // tr black
    ans = square - black_count[sz - 1][x * 2 + 1][y * 2];
    ans += black_count[sz - 1][x * 2][y * 2];
    ans += bl + br;
    if (ans < best_ans) {
        past[sz][x][y] = 20;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2 + 1][y * 2];
    ans += black_count[sz - 1][x * 2 + 1][y * 2 + 1];
    ans += tl + bl;
    if (ans < best_ans) {
        past[sz][x][y] = 21;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2 + 1][y * 2];
    ans += black_count[sz - 1][x * 2][y * 2 + 1];
    ans += tl + br;
    if (ans < best_ans) {
        past[sz][x][y] = 22;
        best_ans = ans;
    }

    // br black
    ans = square - black_count[sz - 1][x * 2 + 1][y * 2 + 1];
    ans += black_count[sz - 1][x * 2][y * 2];
    ans += bl + tr;
    if (ans < best_ans) {
        past[sz][x][y] = 30;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2 + 1][y * 2 + 1];
    ans += black_count[sz - 1][x * 2 + 1][y * 2];
    ans += tl + bl;
    if (ans < best_ans) {
        past[sz][x][y] = 31;
        best_ans = ans;
    }


    ans = square - black_count[sz - 1][x * 2 + 1][y * 2 + 1];
    ans += black_count[sz - 1][x * 2][y * 2 + 1];
    ans += tl + tr;
    if (ans < best_ans) {
        past[sz][x][y] = 32;
        best_ans = ans;
    }

    // bl black
    ans = square - black_count[sz - 1][x * 2][y * 2 + 1];
    ans += black_count[sz - 1][x * 2][y * 2];
    ans += br + tr;
    if (ans < best_ans) {
        past[sz][x][y] = 40;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2][y * 2 + 1];
    ans += black_count[sz - 1][x * 2 + 1][y * 2];
    ans += tl + br;
    if (ans < best_ans) {
        past[sz][x][y] = 41;
        best_ans = ans;
    }

    ans = square - black_count[sz - 1][x * 2][y * 2 + 1];
    ans += black_count[sz - 1][x * 2 + 1][y * 2 + 1];
    ans += tl + tr;
    if (ans < best_ans) {
        past[sz][x][y] = 42;
        best_ans = ans;
    }

    return dp[sz][x][y] = best_ans;
}

void fill_back(int sz, int x, int y, int type) {
    // printf("%d %d %d %d\n", sz, x, y, type);
    if (sz == 0 && type == 1) {
        output[x][y] = '1';
        return;
    }
    if (sz == 0 && type == 0) {
        output[x][y] = '0';
        return;
    }
    if (sz == 0 && type == 2) {
        output[x][y] = output[x][y];
        return;
    }

    if (type == 0)
    {
        fill_back(sz - 1, x * 2, y * 2, 0);
        fill_back(sz - 1, x * 2 + 1, y * 2, 0);
        fill_back(sz - 1, x * 2, y * 2 + 1, 0);
        fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 0);
    } else if (type == 1) {
        fill_back(sz - 1, x * 2, y * 2, 1);
        fill_back(sz - 1, x * 2 + 1, y * 2, 1);
        fill_back(sz - 1, x * 2, y * 2 + 1, 1);
        fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 1);
    } else {
        if (past[sz][x][y] == 10) {
            fill_back(sz - 1, x * 2, y * 2, 1);
            fill_back(sz - 1, x * 2 + 1, y * 2, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 2);
            fill_back(sz - 1, x * 2, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 11) {
            fill_back(sz - 1, x * 2, y * 2, 1);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2, 2);
            fill_back(sz - 1, x * 2, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 12) {
            fill_back(sz - 1, x * 2, y * 2, 1);
            fill_back(sz - 1, x * 2, y * 2 + 1, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 2);
            fill_back(sz - 1, x * 2 + 1, y * 2, 2);
        } else if (past[sz][x][y] == 20) {
            fill_back(sz - 1, x * 2 + 1, y * 2, 1);
            fill_back(sz - 1, x * 2, y * 2, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 2);
            fill_back(sz - 1, x * 2, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 21) {
            fill_back(sz - 1, x * 2 + 1, y * 2, 1);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 0);
            fill_back(sz - 1, x * 2, y * 2, 2);
            fill_back(sz - 1, x * 2, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 22) {
            fill_back(sz - 1, x * 2 + 1, y * 2, 1);
            fill_back(sz - 1, x * 2, y * 2 + 1, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 2);
            fill_back(sz - 1, x * 2, y * 2, 2);
        } else if (past[sz][x][y] == 30) {
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 1);
            fill_back(sz - 1, x * 2, y * 2, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2, 2);
            fill_back(sz - 1, x * 2, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 31) {
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 1);
            fill_back(sz - 1, x * 2 + 1, y * 2, 0);
            fill_back(sz - 1, x * 2, y * 2, 2);
            fill_back(sz - 1, x * 2, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 32) {
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 1);
            fill_back(sz - 1, x * 2, y * 2 + 1, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2, 2);
            fill_back(sz - 1, x * 2, y * 2, 2);
        } else if (past[sz][x][y] == 40) {
            fill_back(sz - 1, x * 2, y * 2 + 1, 1);
            fill_back(sz - 1, x * 2, y * 2, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2, 2);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 41) {
            fill_back(sz - 1, x * 2, y * 2 + 1, 1);
            fill_back(sz - 1, x * 2 + 1, y * 2, 0);
            fill_back(sz - 1, x * 2, y * 2, 2);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 2);
        } else if (past[sz][x][y] == 42) {
            fill_back(sz - 1, x * 2, y * 2 + 1, 1);
            fill_back(sz - 1, x * 2 + 1, y * 2 + 1, 0);
            fill_back(sz - 1, x * 2 + 1, y * 2, 2);
            fill_back(sz - 1, x * 2, y * 2, 2);
        } else {
            printf("you messed up\n");
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> row;
        for (int j = 0; j < n; j++) {
            output[i][j] = row[j];
        }
    }
    p = 0;
    int thing = n;
    while (thing != 1) {
        p++;
        thing >>= 1;
    }
    // printf("p = %d\n", p);
    count_black(p, 0, 0);
    // printf("%d\n", count_black(p, 0, 0));
    // printf("%d\n", count_white(p, 0, 0));
    // printf("%d\n", black_count[p - 1][0][0]);
    // printf("%d\n", white_count[p - 1][0][0]);
    // printf("%d\n", black_count[p - 1][1][1]);
    // printf("%d\n", white_count[p - 1][1][1]);

    printf("%d\n", search(p, 0, 0));

    fill_back(p, 0, 0, 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}