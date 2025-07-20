#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> diffs;
ll n, past, ans = 0, total_sum = 0, average = 0, upper = 0, lower = 0;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    cin >> past;
    if (n == 1)
    {
        printf("%lld\n", ans);
        return 0;
    }
    for (ll i = 1, a, diff; i < n; i++)
    {
        cin >> a;
        diff = a - past;
        total_sum += diff;
        diffs.push_back(diff);
        past = a;
    }
    average = total_sum / (n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (diffs[i] > average) {
            upper += diffs[i] - average;
        } else if (diffs[i] < average) {
            lower += average - diffs[i];
        }
    }

    ans = max(upper, lower);
    upper = 0;
    lower = 0;
    average += 1;
    for (int i = 0; i < n - 1; i++) {
        if (diffs[i] > average) {
            upper += diffs[i] - average;
        } else if (diffs[i] < average) {
            lower += average - diffs[i];
        }
    }
    ans = min(ans, max(upper, lower));
    upper = 0;
    lower = 0;
    average -= 2;
    for (int i = 0; i < n - 1; i++)
    {
        if (diffs[i] > average)
        {
            upper += diffs[i] - average;
        }
        else if (diffs[i] < average)
        {
            lower += average - diffs[i];
        }
    }

    printf("%lld\n", min(ans, max(upper, lower)));

    return 0;
}