#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll nums[200010];
ll n, m, cur_sum = 0, ans = 0;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    ll l = 1, r = 1;
    while (r <= n)
    {
        // printf("cur sum = %d %d %d\n", cur_sum, l, r);
        if (cur_sum + nums[r] < m)
        {
            cur_sum += nums[r];
            r++;
            ans = max(ans, r - l);
        }
        else
        {
            if (l < r) cur_sum -= nums[l];
            l++;
            r = max(r, l);
        }
    }
    printf("%d\n", ans);

    return 0;
}