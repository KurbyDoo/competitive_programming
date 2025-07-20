#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t;
int dsu1[200010], dsu2[200010], sz1[200010], sz2[200010];
int n, m1, m2;

int find(int a, int (&dsu)[200010]) {
    if (dsu[a] == a) return a;
    return dsu[a] = find(dsu[a], dsu);
}

void join(int a, int b, int (&dsu)[200010], int (&sz)[200010])
{
    a = find(a, dsu);
    b = find(b, dsu);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        dsu[b] = a;
    }
}

void solve() {
    vector<pii> edges;
    vector<pii> edges2;
    int ans = 0;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        dsu1[i] = i;
        dsu2[i] = i;
        sz1[i] = 1;
        sz2[i] = 1;
    }

    for (int i = 0, u, v; i < m1; i++) {
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (int i = 0, u, v; i < m2; i++) {
        cin >> u >> v;
        edges2.push_back({u, v});
        join(u, v, dsu2, sz2);
    }

    for (auto [a, b]: edges) {
        if (find(a, dsu2) == find(b, dsu2)) {
            join(a, b, dsu1, sz1);
        } else {
            ans += 1;
        }
    }

    for (auto [a, b]: edges2) {
        if (find(a, dsu1) != find(b, dsu1)) {
            join(a, b, dsu1, sz1);
            ans += 1;
        }
    }

    printf("%d\n", ans);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}