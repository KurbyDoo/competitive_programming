#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, int> pldi;
priority_queue<pldi> good;
double num[200010];
double denom[200010];
double ans = 0;
int n, k;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> denom[i];
    }
    // for (int i = 0; i < n; i++) {
        // printf("%f/%f ", num[i], denom[i]);
    // }
    for (int i = 0; i < n; i++) {
        good.push({(denom[i] - num[i]) / (denom[i] * (denom[i] + 1.0)), i});
    }

    while (k--)
    {
        auto [a, b] = good.top();
        good.pop();
        num[b] += 1;
        denom[b] += 1;
        good.push({(denom[b] - num[b]) / (denom[b] * (denom[b] + 1.0)), b});
    }

    // for (int i = 0; i < n; i++) {
        // printf("%f/%f ", num[i], denom[i]);
    // }
    // printf("\n");
    for (int i = 0; i < n; i++) {
        ans += (num[i]) / (denom[i]);
        // printf("ans = %f + %f: %f %f\n", ans, (num[i]) / (denom[i]), (num[i]), (denom[i]));
    }
    ans /= double(n);
    printf("%f\n", ans * 100.0);

    return 0;
}