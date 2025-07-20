#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
unordered_map<int, int> behind;
unordered_map<int, int> ahead;
int n, q, nums[200010];
set<int> cur_nums;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        cur_nums.insert(nums[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        ahead[nums[i]] = nums[i - 1];
        behind[nums[i]] = nums[i + 1];
    }
    ahead[nums[1]] = -1;
    behind[nums[n]] = -1;
    cin >> q;
    for (int i = 0, op, x, y; i < q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            cur_nums.insert(y);
            behind[y] = behind[x];
            ahead[y] = x;
            ahead[behind[y]] = y;
            behind[x] = y;
        }
        else
        {
            cin >> x;
            cur_nums.erase(x);
            ahead[behind[x]] = ahead[x];
            behind[ahead[x]] = behind[x];
        }
    }

    int start = -1;
    for (int number : cur_nums)
    {
        if (ahead[number] == -1)
        {
            start = number;
        }
    }

    while (behind[start] != -1)
    {
        printf("%d ", start);
        start = behind[start];
    }
    printf("%d\n", start);

    return 0;
}