// Kurbydoo
// July 8th, 2023
// No Cycle [Olympiads School]
// https://dmoj.ca/problem/oly23practice12
#include <bits/stdc++.h>
using std::cin;
using std::max;
using std::memset;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

unordered_map<int, vector<int>> one_way_graph;
int out_count[100010];

int n, m, k;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0, ai, bi; i < m; i++) {
        cin >> ai >> bi;
        one_way_graph[ai].push_back(bi);
        out_count[ai]

    }




    
    return 0;
}