#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
unordered_map<int, vector<int>> graph;
int n, a, b;
int search(int n, int past) {
    int c = 1;
    for (int p: graph[n]) {
        if (p != past) c += search(p, n);
    }
    return c;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    for (int e: graph[1]) {
        ans = max(ans, search(e, 1));
    }
    printf("%d\n", n - ans);
}