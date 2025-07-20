#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int colour_counts[500010];
int l[500010];
int r[500010];
int dsu[500010];
int par_color[500010];
int n, q, t, x, c;
int find(int a) {
    if (dsu[a] == a) {
        return a;
    }
    return dsu[a] = find(dsu[a]);
}
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (r[a] - l[a] < r[b] - l[b]) {
            swap(a, b);
        }
        dsu[b] = a;
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        colour_counts[i] = 1;
        par_color[i] = i;
        l[i] = i;
        r[i] = i;
    }

    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> x >> c;
            x = find(x);
            int sz = r[x] - l[x] + 1;
            colour_counts[par_color[x]] -= sz;
            colour_counts[c] += sz;
            par_color[x] = c;
            if (par_color[find(l[x] - 1)] == par_color[x]) {
                join(l[x] - 1, x);
            }
            if (par_color[find(r[x] + 1)] == par_color[x]) {
                join(r[x] + 1, x);
            }
            
        } else {
            cin >> c;
            printf("%d\n", colour_counts[c]);
        }

        // for (int i = 1; i <= n; i++) {
        //     printf("%d = [%d %d]\n", i, l[find(i)], r[find(i)]);
        // }
    }

        return 0;
}