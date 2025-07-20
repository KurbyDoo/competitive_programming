#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll ci[100];
vector<ll> animals[150];

int get_ith(int i, int mask) {
    int val = 1;
    for (int j = 1; j < i; j++) {
        val *= 3;
    }
    // printf("get_ith(%d, %d) = %d / %d % 3 = %d\n", i, mask, mask, val, (mask / val) % 3);
    return (mask / val) % 3;
}

bool test_zoo(int mask) {
    for (int i = 1; i <= m; i++) {
        int counter = 0;
        for (int zoo: animals[i]) {
            counter += get_ith(zoo, mask);
        }
        if (counter < 2) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ci[i];
    }
    
    for (int i = 1; i <= m; i++) {
        ll k, a;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            animals[i].push_back(a);
        }
    }

    ll ans = 100000000000;
    int total_masks = 1;
    for (int i = 1; i <= n; i++) {
        total_masks *= 3;
    }
    for (int i = 1; i <= total_masks; i++) {
        bool works = test_zoo(i);
        if (!works) continue;
        ll cost = 0;
        for (int j = 1; j <= n; j++) {
            cost += get_ith(j, i) * ci[j];
        }
        // for (int k = 1; k <= n; k++) {
        //     printf("%d ", get_ith(k, i));
        // }
        // printf("\n");
        ans = min(ans, cost);
    }
    printf("%lld\n", ans);
    return 0;
}
