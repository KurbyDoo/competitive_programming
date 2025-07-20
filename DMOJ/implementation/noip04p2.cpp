#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans = 0;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    while (pq.size() > 1)
    {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    printf("%lld\n", ans);
}