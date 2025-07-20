#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int parent[200010];
int sz[200010];
vector<int> largest[200010];
int n, q, a, b, c;

int find(int a) {
  if (parent[a] == a) {
    return a;
  }
  return parent[a] = find(parent[a]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (sz[b] > sz[a]) {
      swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
    for (int temp: largest[b]) {
      largest[a].push_back(temp);
    }
    sort(largest[a].begin(), largest[a].end(), greater<int>());
    while (largest[a].size() > 10)
      largest[a].pop_back();
  }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
      sz[i] = 1;
      largest[i].push_back(i);
    }

    for (int i = 0; i < q; i++) {
      cin >> a >> b >> c;
      if (a == 1) {
        join(b, c);
      } else if (a == 2)
      {
        b = find(b);
        if (largest[b].size() < c) printf("-1\n");
        else printf("%d\n", largest[b][c - 1]);
      }

    }
      return 0;
}