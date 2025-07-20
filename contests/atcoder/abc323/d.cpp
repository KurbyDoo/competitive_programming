# include <bits/stdc++.h>

using std::cin;
using std::greater;
using std::pair;
using std::priority_queue;
using std::sort;
using std::unordered_map;
using std::vector;
typedef long long ll;
typedef pair<ll, ll> pii;

// unordered_map<ll, int> carry;

int n;
ll remain = 0;
// vector<pii> sorted_slimes;
priority_queue<pii, vector<pii>, greater<pii>> sorted_slimes;

int main() {
    cin >> n;
    for (ll i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        sorted_slimes.push({a, b});
    }

    while (!sorted_slimes.empty()) {
        ll current_size = sorted_slimes.top().first;
        ll current_count = 0;
        while (!sorted_slimes.empty() && sorted_slimes.top().first == current_size)
        {
            current_count += sorted_slimes.top().second;
            sorted_slimes.pop();
        }
        // printf("size = %lld count = %lld\n", current_size, current_count);
        if (current_count > 1) {
            sorted_slimes.push({current_size * 2, current_count / 2});
        }
        remain += current_count % 2;
    }
    printf("%lld\n", remain);

    return 0;

}
// 5
// 2 2
// 4 1
// 8 1
// 16 1
// 32 2