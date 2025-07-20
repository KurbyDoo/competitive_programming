#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> diffs;
ll n, past, ans = 0, total_sum = 0, average = 0;

// Find the distance from the average
// Since each operation will decrease 1 number and increase another
// The total number of operations is the max of the two distance from below and above the average
ll find_diff(ll average) {
    ll upper = 0, lower = 0;
    for (int i = 0; i < n - 1; i++) {
        if (diffs[i] > average) {
            upper += diffs[i] - average;
        } else if (diffs[i] < average) {
            lower += average - diffs[i];
        }
    }

    return max(upper, lower);
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> past;
    if (n == 1) { // If n = 1, then divide by 0 error
        printf("0\n");
        return 0;
    }

    // Take input and find the differences between every number
    for (ll i = 1, a, diff; i < n; i++) {
        cin >> a;
        diff = a - past;
        total_sum += diff;
        diffs.push_back(diff);
        past = a;
    }

    // Find the average by dividing the sum of all differences
    // by the number of differences (n - 1)
    average = total_sum / (n - 1);

    // Find the number of operations for the average, average + 1, and average - 1
    // Print the best one from those three
    ans = find_diff(average);
    ans = min(find_diff(average + 1), ans);
    ans = min(find_diff(average - 1), ans);

    printf("%lld\n", ans);

    return 0;
}