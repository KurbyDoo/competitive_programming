#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int adj[110][110];
int n;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> adj[i][j];
        if (adj[i][j] == 1) printf("%d ", j + 1);
      }
      printf("\n");
    }
      return 0;
}