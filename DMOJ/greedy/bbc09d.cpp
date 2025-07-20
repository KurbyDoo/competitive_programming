#include <iostream>
#include <algorithm>

using std::sort;
using std::cin;

typedef long long ll;

ll diff[1000010] = {0};
ll cost[1000010] = {0};

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    ll v;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> v;
        diff[i] = v;
    }

    sort(diff, diff + n);

    ll totalCost = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("cost = %d * %d\n", diff[i], diff[n - 1 - i]);
        totalCost = (totalCost + ((diff[i] * diff[n - 1 - i]) % 10007)) % 10007;
    }

    printf("%llu\n", totalCost);
    return 0;
}