#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
vector<ll> pf;
ll a, b;
ll not_prime[1000010];
int main() {
    cin >> a >> b;
    not_prime[1] = false;

    for (int i = 2; i <= 1000000; i++) {
        if (!not_prime[i]) {
            int j = i * 2;
            while (j <= 1000000) {
                not_prime[j] = true;
                j += i;
            }
        }
    }
    // for (int i = 1; i < 25; i++) {
    //     printf("%d %d\n", i, not_prime[i]);
    // }
    // printf("\n");
    int s = sqrt(a);
    bool divided = false;
    for (int i = 2; i <= s; i++)
    {
        // printf("a = %d i = %d %d\n", a, i, int(sqrt(a)));
        if (not_prime[i]) continue;
        if (a % i == 0)
        {
            ll cnt = 0;
            while (a % i == 0)
            {
                cnt += 1;
                a /= i;
            }
            printf("modding %d %d\n", i, cnt);
            if (!divided && cnt % 2 == 0) {
                cnt /= 2;
            }
            pf.push_back(cnt);
        }
    }
    if (pf.size() == 0) {
        pf.push_back(1);
    }
    ll out = 1;
    for (int e: pf) {
        out = ((out % mod) * (((((e % mod) * (b % mod)) % mod) + 1) % mod)) % mod;
        printf("%d %lld\n", e, out);
    }
    if (!divided) {
        printf("%lld\n", (out % mod) * ((b / 2)% ))
    }
    printf("%lld\n", (((out % mod) * (b % mod)) % mod) / 2);
    printf("%lld\n", ((((((355 * 168) % mod) * ((168 * 168) % mod)) % mod) * 167) % mod) / 2);
    printf("%lld\n", ((((355 * 168 * 168 * 168) % mod) * 167) % mod));
    printf("%lld\n", ((((355 * 168 * 168 * 168) % mod) * 167 / 2) % mod));
    return 0;
}