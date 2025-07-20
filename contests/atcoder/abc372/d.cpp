#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> buildings;
int loc[200010];
int bit[200010];
int ans[200010];
int chain[200010];
int n, hi;
// min idex of thing greater than me
void update(int index, int v) {
    for (int j = index; j <= 200005; j += j & -j) {
        bit[j] = max(bit[j], v);
    }
}

int query(int index) {
    int s = 0;
    for (int j = index; j > 0; j -= j & -j) {
        s = max(bit[j], s);
    }
    return s;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> hi;
      loc[hi] = i;
      buildings.push_back(hi);
    }
    buildings.push_back(0);
    for (int i = n; i > 0; i--) {
        ans[i] = chain[buildings[i]];
        // printf("front chain %d -> %d\n", buildings[i], ans[i]);
        int min_index = n - query(n + 1 - buildings[i - 1]);
        chain[buildings[i - 1]] = chain[buildings[min_index]] + 1;
        // printf("min %d | height %d chain %d\n", min_index, buildings[min_index], chain[buildings[min_index]]);
        update(n + 1 - buildings[i - 1], n - i + 1);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);

    }

    return 0;
}