#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll n, min_bucket = 9999999999, left_bounds, right_bounds;
ll nums[1000010];
ll total = 0;
vector<pii> ranges;
vector<set<ll>> sorted_nums;
unordered_map<int, unordered_map<ll, int>> num_count;

void merge_ranges()
{
    int set_1 = 0, set_2 = 1;
    int offset = 0;
    while (set_2 < ranges.size())
    {
        if (*sorted_nums[set_1].rbegin() < *sorted_nums[set_2].begin())
        {
            for (ll e : sorted_nums[set_2])
            {
                sorted_nums[set_1].insert(e);
                num_count[set_1][e] = num_count[set_2][e];
            }
            ranges[set_1] = {ranges[set_1].first, ranges[set_2].second};
            ranges.erase(ranges.begin() + set_2);
            sorted_nums.erase(sorted_nums.begin() + set_2);
            offset += 1;
        }
        else
        {
            set_1 += 1;
            set_2 += 1;
            // printf("leaving %d untouched\n", set_1);
            // printf("range %d to %d\n", ranges[set_1].first, ranges[set_1].second);
            for (ll e : sorted_nums[set_1])
            {
                num_count[set_1][e] = num_count[set_1 + offset][e];
                // printf("%lld: %d ", e, num_count[set_1][e]);
            }
            // printf("\n");
        }
    }
    for (ll e : sorted_nums[set_1])
    {
        num_count[set_1][e] = num_count[set_1 + offset][e];
        // printf("%lld: %d ", e, num_count[set_1][e]);
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        total += nums[i];
        nums[i + n] = nums[i];
        if (nums[i] < min_bucket)
        {
            min_bucket = nums[i];
            left_bounds = i;
            right_bounds = i + n - 1;
        }
    }

    int lft = left_bounds;
    int cur_range = 0;
    sorted_nums.push_back(set<ll>());
    sorted_nums[cur_range].insert(nums[lft]);
    num_count[cur_range][nums[lft]] += 1;

    for (int i = left_bounds + 1; i <= right_bounds; i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            // printf("adding range %d - %d\n", lft, i - 1);
            ranges.push_back({lft, i - 1});
            sorted_nums.push_back(set<ll>());
            lft = i;
            cur_range += 1;
        }
        sorted_nums[cur_range].insert(nums[i]);
        num_count[cur_range][nums[i]] += 1;
    }
    ranges.push_back({lft, right_bounds});

    // printf("total = %d\n", total);
    // for (int i = 0; i < ranges.size(); i++)
    // {
    //     printf("range %d to %d\n", ranges[i].first, ranges[i].second);
    //     for (ll e : sorted_nums[i])
    //     {
    //         printf("%lld: %d ", e, num_count[i][e]);
    //     }
    //     printf("\n");
    // }

    for (int i = 1; i <= n; i++)
    {
        if (total == min_bucket * n) {
            printf("%lld\n", min_bucket * n);
            continue;
        }
        for (int i = 0; i < ranges.size(); i++)
        {
            // printf("%d - %d\n", *sorted_nums[i].begin(), *sorted_nums[i].rbegin());
            total += *sorted_nums[i].begin() - *sorted_nums[i].rbegin();

            // printf("adding %d to %d\n", *sorted_nums[i].begin(), i);
            // printf("count bef add %d = %d\n", *sorted_nums[i].begin(), num_count[i][*sorted_nums[i].begin()]);
            num_count[i][*sorted_nums[i].begin()] += 1;
            sorted_nums[i].insert(*sorted_nums[i].begin());
            // printf("count aft add %d = %d\n", *sorted_nums[i].begin(), num_count[i][*sorted_nums[i].begin()]);

            // printf("removing %d from %d\n", *sorted_nums[i].rbegin(), i);
            // printf("count bef sub %d = %d\n", *sorted_nums[i].rbegin(), num_count[i][*sorted_nums[i].rbegin()]);
            if (num_count[i][*sorted_nums[i].rbegin()] == 1)
            {
                sorted_nums[i].erase(*sorted_nums[i].rbegin());
            }
            else
            {
                num_count[i][*sorted_nums[i].rbegin()] -= 1;
            }
            // printf("count aft sub %d = %d\n", *sorted_nums[i].rbegin(), num_count[i][*sorted_nums[i].rbegin()]);
        }
        // printf("before merge --- at %d total = %d\n", i, total);
        // for (int i = 0; i < ranges.size(); i++)
        // {
        //     printf("range %d to %d\n", ranges[i].first, ranges[i].second);
        //     for (ll e : sorted_nums[i])
        //     {
        //         printf("%lld: %d ", e, num_count[i][e]);
        //     }
        //     printf("\n");
        // }

        merge_ranges();

        // printf("after merge ---- at %d total = %d\n", i, total);
        // for (int i = 0; i < ranges.size(); i++)
        // {
        //     printf("range %d to %d\n", ranges[i].first, ranges[i].second);
        //     for (ll e : sorted_nums[i])
        //     {
        //     printf("%lld: %d ", e, num_count[i][e]);
        //     }
        //     printf("\n");
        // }
        // printf("total = %lld\n", total);
        printf("%lld\n", total);
    }
    return 0;
}

// 11
// 1 2 3 4 3 4 5 6 4 2 1

// 7
// 1 1 1 1 1 1 1

// 7
// 8 8 8 8 8 8 1

// 8
// 1 8 1 8 1 8 1 8

// 8
// 1 2 3 4 2 3 4 5

// 7
// 7 6 5 4 3 2 1