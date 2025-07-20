// KurbyDoo
// June 20th, 2024
// Least Multiple
// https://dmoj.ca/problem/oly22practice33
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool is_prime[1010];
vector<pll> pairs[110];
vector<ll> primes;
ll t, k, ei;

void get_pairs(ll pr, int i) {
    pairs[i].push_back({pr, 1});
    ll p = pr * pr;
    while(pairs[i][pairs[i].size() - 1].second * pr + 1 <= 1e18 / pr) {
        pairs[i].push_back({p, pairs[i][pairs[i].size() - 1].second * pr + 1});
        p *= pr;
    }
}

void get_primes() {
    for (int i = 0; i <= 620; i++) {
        is_prime[i] = true;
    }
    for (ll i = 2; i <= 620; i++)
    {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i; j <= 620; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

ll get_min(ll num, ll i) {
    ll amount = 0;
    for (int j = pairs[i].size() - 1; j >= 0; j--) {
        if (num >= pairs[i][j].second) {
            ll times = num / pairs[i][j].second;
            amount += (pairs[i][j].first) * times;
            num -= pairs[i][j].second * times;
            // printf("using %lld %lld %d times\n", pairs[i][j].first, pairs[i][j].second, times);
        }
    }
    // printf("%lld\n", amount);
    return amount;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    get_primes();

    for (int i = 0; i < 100; i++) {
        get_pairs(primes[i], i);
    }

    for (int _ = 0; _ < t; _++) {
        ll ans = 0;
        cin >> k;
        for (ll i = 0; i < k; i++) {
            cin >> ei;
            ans = max(ans, get_min(ei, i));
        }
        printf("%lld\n", ans == 0 ? 1 : ans);
    }

    return 0;
}