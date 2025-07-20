#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
set<int> hits[5];
unordered_map<int, int> used[5];
int points[100010];
int t, c;
bool is_target[200010];
string moves;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t >> c;
    for (int i = 0, a; i < t; i++)
    {
        cin >> a;
        is_target[a + 100000] = true;
    }
    cin >> moves;
    for (int offset = 0; offset < 5; offset++)
    {
        int pos = 100000 + offset - 2;
        for (int i = 0; i < c; i++)
        {
            if (moves[i] == 'L')
                pos -= 1;
            if (moves[i] == 'R')
                pos += 1;
            if (moves[i] == 'F')
            {
                if (is_target[pos])
                {
                    // printf("hit %d\n", pos);
                    hits[offset].insert(pos);
                    used[offset][pos] += 1;
                    // printf("used[%d][%d] = %d\n", offset, pos, used[offset][pos]);
                }
            }
            if (offset == 2)
            {
                points[i + 1] = hits[offset].size();
            }
        }
        // printf("offset %d gives = %d\n", offset, hits[offset].size());
    }

    int ans = 0;
    int pos = 100000;
    int best = 0;
    int potential = 0;
    for (int i = 0; i < c; i++)
    {
        if (moves[i] == 'L')
        {
            potential = hits[2].size();
            best = max(best, points[i] + potential);
            pos -= 1;
            // printf("move l = %d %d %d\n", best, points[i], potential);

            // FIRE (MOVE RIGHT)
            potential = hits[3].size();
            if (is_target[pos + 1] && !used[3][pos + 1])
            {
                potential += 1;
            }
            best = max(best, points[i] + potential);

            // MOVE RIGHT
            potential = hits[4].size();
            best = max(best, points[i] + potential);
        }
        else if (moves[i] == 'R')
        {
            potential = hits[2].size();
            best = max(best, points[i] + potential);
            // printf("move R = %d %d %d\n", best, points[i], potential);
            pos += 1;

            // FIRE (MOVE LEFT)
            potential = hits[1].size();
            if (is_target[pos - 1] && !used[1][pos - 1])
            {
                // printf("%d has not been hit before\n", pos - 1);
                potential += 1;
            }
            best = max(best, points[i] + potential);
            // printf("F from R = %d size = %d\n", potential, hits[1].size());

            // MOVE LEFT
            potential = hits[0].size();
            best = max(best, points[i] + potential);
        }
        else if (moves[i] == 'F')
        {
            potential = hits[2].size();
            best = max(best, points[i] + potential);
            // printf("do nothing = %d pt = %d pot = %d\n", best, points[i], potential);

            // MOVE LEFT
            potential = hits[1].size();
            if (used[1][pos - 1] == 1)
            {
                potential -= 1;
            }
            // printf("left pot = %d at %d\n", potential, i);
            best = max(best, points[i] + potential);
            // MOVE RIGHT
            potential = hits[3].size();
            if (used[3][pos + 1] == 1)
            {
                potential -= 1;
            }
            // printf("right pot = %d at %d\n", potential, i);
            best = max(best, points[i] + potential);
        }
            // STAY
            for (int offset = 0; offset < 5; offset++)
            {
                used[offset][pos] = 0;
                hits[offset].erase(pos);
                is_target[pos] = false;
            }
    }
    printf("%d\n", best);

    return 0;
}
// 5 13
// 0 1 2 3 7
// FRFRFRFRFRFRF

// 1 5
// 1
// FFFFF

// 1 5
// 2
// RRRRR

// 2 5
// 0 -1
// FFFRF

// 3 5
// 0 1 2
// FFFFF

// 3 5
// 0 -1 -2
// FLFLF