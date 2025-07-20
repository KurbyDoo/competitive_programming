#include <bits/stdc++.h>
using namespace std;
int n, c[2010], a[2010];
int dist[2010], total;
typedef pair<int, int> pii;
map<int, vector<int>> graph;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        dist[i] = 99999999;
        cin >> c[i];
        for (int j = i - c[i]; j < i; j++) {
            graph[j].push_back(i);
        }
    }
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        int cd, cn;
        tie(cd, cn) = pq.top();
        pq.pop();
        if (a[cn] > 0) cd = 0;
        for (int e: graph[cn]) {
            if (dist[e] > cd + 1) {
                dist[e] = cd + 1;
                pq.push({cd + 1, e});
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > 0) total += dist[i];
    }
    printf("%d\n", total);
    return 0;
}