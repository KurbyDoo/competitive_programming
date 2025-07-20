// Kurbydoo
// April 26th, 2023
// Another Contest 7 Problem 3 - Network Connections
// https://dmoj.ca/problem/acc7p3
// Template min spanning tree
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
using std::sort;
using std::priority_queue;
using std::swap;
using std::greater;

const int MM = 1e5 + 10;
typedef pair<int, int> pi;
int n, m, f, v1, v2;
int past[MM];
int rank[MM];
vector<pi> people;
priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;

int find(int a) {
    if (past[a] == a) {
        return a;
    }

    return past[a] = find(past[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rank[a] > rank[b]) {
            swap(a, b);
        }

        past[b] = a;
        if (rank[a] == rank[b]) {
            rank[a] += 1;
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> f;
        people.push_back({f, i});
        rank[i] = 1;
        past[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        join(v1, v2);
    }

    sort(people.begin(), people.end());

    for (int i = 1; i < n; i++) {
        pq.push({people[i].first - people[i - 1].first, {people[i].second, people[i - 1].second}});
    }

    int minCost = 0;
    while (!pq.empty()) {
        int cost, e1, e2;
        cost = pq.top().first;
        e1 = pq.top().second.first;
        e2 = pq.top().second.second;
        pq.pop();

        if (find(e1) == find(e2)) continue;
        minCost += cost;
        join(e1, e2);
    }

    printf("%d\n", minCost);

    return 0;
}

// 4 0
// 4 3 2 1
