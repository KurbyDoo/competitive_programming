#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll word_lengths[200010];
ll max_word_length, total_length;

bool solve(ll max_length) {
    int lines = 0;
    ll cur_line = -1;
    for (int i = 0; i < n; i++) {
        if (cur_line + word_lengths[i] + 1 <= max_length) {
            cur_line += word_lengths[i];
            cur_line++;
        } else {
            lines++;
            if (lines >= m) return false;
            cur_line = word_lengths[i];
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    total_length = -1;
    for (int i = 0; i < n; i++) {
        cin >> word_lengths[i];
        max_word_length = max(max_word_length, word_lengths[i]);
        total_length += word_lengths[i];
        total_length++;
    }

    ll l = max_word_length, r = total_length;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        // printf("at %lld\n", mid);
        if (solve(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", l);
}
