#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, pairs, single;
vector<ll> items;
ll unbal = 0, a;
int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    pairs = n - m;
    single = m - pairs;
    for (int i = 0; i < n; i++) {
        cin >> a;
        items.push_back(a);
    }
    sort(items.begin(), items.end());
    // for (int i = 0; i < n; i++) {
    //     printf("%lld\n", items[i]);
    // }
        for (int i = 0; i < m; i++)
        {
            if (i < pairs)
            {
                // printf("%d %d\n", i, n - 1 - single);
                unbal += (items[i] + items[n - 1 - single - i]) * (items[i] + items[n - 1 - single - i]);
            }
            else
            {
                // printf("%d\n", i + pairs);
                unbal += items[i + pairs] * items[i + pairs];
            }
        }
    printf("%lld\n", unbal);
}
