#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, mg, mh, ans = 999999999, u, v, a, b;
bool graph1[9][9], graph2[9][9];
int costs[9][9];
int perms[9];
int find_cost() {
  int cost = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (graph1[i][j] == graph2[perms[i]][perms[j]]) continue;
      cost += costs[perms[i]][perms[j]];
    }
  }
  return cost;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;

    cin >> mg;
    for (int i = 0; i < mg; i++) {
      cin >> u >> v;
      graph1[u][v] = true;
      graph1[v][u] = true;
    }

    cin >> mh;
    for (int i = 0; i < mh; i++) {
      cin >> a >> b;
      graph2[a][b] = true;
      graph2[b][a] = true;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        cin >> costs[i][j];
        costs[j][i] = costs[i][j];
      }
    }
    
    for (int i = 1; i <= n; i++) {
      perms[i] = i;
    }

    do {
      ans = min(ans, find_cost());
    } while (next_permutation(perms + 1, perms + n + 1));
    printf("%d\n", ans);
    return 0;
}