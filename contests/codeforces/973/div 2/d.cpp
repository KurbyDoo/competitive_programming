#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int t;

// broken
ll solve() {
    int n;
    ll nums[200010];
    stack<pll> st;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    ll total = 0;
    ll denom = 0;
    for (int i = n; i > 0; i--) {
        total += nums[i];
        denom += 1;
        if (st.empty() || nums[i] < st.top().first) {
            st.push({nums[i], 1});
        } else if (nums[i] == st.top().first) {
            ll val = st.top().first;
            ll amount = st.top().second;
            st.pop();
            amount += 1;
            st.push({val, amount});
        } else if (nums[i] > st.top().first) {
            ll total_val = nums[i];
            ll total_amount = 1;
            while (!st.empty() && (total_val + st.top().first * st.top().second) / (total_amount + st.top().second) >= st.top().first) {
                total_val += st.top().first;
                total_amount += st.top().second;
                st.pop();
            }

            if (total_val % total_amount == 0) {
                ll val = total_val / total_amount;
                if (!st.empty() && st.top().first == total_val / total_amount) {
                    total_amount += st.top().second;
                    st.pop();
                }
                st.push({val, total_amount});
            } else {
                ll val = total_val / total_amount + 1;
                ll temp_amount = total_val % total_amount;
                if (!st.empty() && st.top().first == total_val + 1) {
                    temp_amount += + st.top().second;
                    st.pop();
                }
                st.push({val + 1, temp_amount});
                st.push({val, total_amount - (total_val % total_amount)});
            }

            // ll diff = nums[i] - st.top().first;
            // ll val = st.top().first;
            // ll amount = st.top().second;
            // st.pop();
            // if (st.empty() || st.top().first != val + 1) {
            //     st.push({val + 1, diff});
            //     amount -= diff;
            //     amount += 1;
            //     st.push({val, amount});
            // } else {
            //     ll val2 = st.top().first;
            //     ll amount2 = st.top().second;
            //     st.pop();
            //     st.push({val2, amount2 + diff});
            //     amount -= diff;
            //     amount += 1;
            //     st.push({val, amount});
            // }
        }
    }

    ll smallest = st.top().first;
    ll largest = st.top().first;
    while (!st.empty()) {
        if (st.top().second > 0) {
            smallest = min(smallest, st.top().first);
            largest = max(st.top().first, largest);

        }
        printf("(%d %d), ", st.top().first, st.top().second);
        st.pop();
    }
    printf("\n");

    return largest - smallest;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;
    for (int _ = 0; _ < t; _++) {
        printf("%lld\n", solve());
    }
    return 0;
}