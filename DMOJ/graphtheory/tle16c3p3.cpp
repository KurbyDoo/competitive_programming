// Kurbydoo
// April 26th, 2023
// TLE '16 Contest 3 P3 - Mysterious Package
// https://dmoj.ca/problem/tle16c3p3
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
using std::queue;

int start, end;
int n, p, s, si;
vector<int> periods[510];
vector<int> classes[510];
unordered_map<int, pair<int, int>> best;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> start >> end;
    for (int i = 1; i <= n; i++) {
        cin >> p >> s;
        for (int j = 0; j < s; j++) {
            cin >> si;
            best[si] = {1000, 1000};
            classes[i].push_back(si);
        }
        periods[p].push_back(i);
    }

    best[start] = {0, 1000};
    for (int period = 1; period <= 500; period++) {
        for (int c: periods[period]) {
            int minP = 1000;
            for (int student: classes[c]) {
                minP = min(minP, best[student].first);
            }

            for (int student: classes[c]) {
                if (minP + 1 < best[student].first) {
                    best[student] = {minP + 1, period};
                }
            }

        }
    }

    // printf("student id = \n");
    // for (auto const& [key, val]: best) {
    //     printf("%4d ", key);
    // }
    // printf("\n");
    // printf("min student passes = \n");
    // for (auto const& [key, val]: best) {
    //     printf("%4d ", val.first);
    // }
    // printf("\n");

    // printf("min student passes = \n");
    // for (auto const& [key, val]: best) {
    //     printf("%4d ", val.second);
    // }
    // printf("\n");

    if (best[end].first != 1000) {
        printf("%d\n%d\n", best[end].first, best[end].second);
    } else {
        printf("delivery failure");
    }
    return 0;
}