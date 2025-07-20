#include <bits/stdc++.h>

using std::cin;
using std::greater;
using std::pair;
using std::priority_queue;
using std::sort;
using std::vector;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> query;

const int maxsize = 100010;

int n, q;
ll bit[maxsize];
ll psa[maxsize];
ll ans[maxsize];
priority_queue<pii, vector<pii>, greater<pii>> numsPQ;
priority_queue<query, vector<query>, greater<query>> queryPq;

void update(int index, int val) {
    while (index <= maxsize) {
        bit[index] += val;
        index += index & -index;
    }
}

ll smaller(int index) {
    ll total = 0;
    while (index > 0)
    {
        total += bit[index];
        index -= index & -index;
    }
    return total;
}

ll answer(int l, int r) {
    return smaller(r) - smaller(l - 1);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> psa[i];
        numsPQ.push({psa[i], i});
        psa[i] += psa[i - 1];
    }

    cin >> q;
    for (int i = 1, a, b, c; i <= q; i++)
    {
        cin >> a >> b >> c;
        queryPq.push({{c, i}, {a + 1, b + 1}});
    }


    while (!queryPq.empty()) {
        int val, idx, l, r;
        val = queryPq.top().first.first;
        idx = queryPq.top().first.second;
        l = queryPq.top().second.first;
        r = queryPq.top().second.second;
        queryPq.pop();

        // printf("doing q %d %d %d %d\n", val, idx, l, r);
        while (!numsPQ.empty() && numsPQ.top().first < val) {
            int a, b;
            a = numsPQ.top().first;
            b = numsPQ.top().second;
            numsPQ.pop();
            update(b, a);
            // printf("added %d at %d\n", a, b);
        }
        // printf("%llu - %llu - 2 * %llu\n", psa[r], psa[l - 1], answer(l, r));
        ans[idx] = (psa[r] - psa[l - 1]) - (answer(l, r));
        // printf("ans %llu\n", ans[idx]);
    }

    for (int i = 1; i <= q; i++) {
        printf("%llu\n", ans[i]);
    }
        return 0;
}
// 5
// 5 4 3 2 1
// 5
// 0 4 1
// 0 4 2
// 0 4 3
// 0 4 4
// 0 4 5

// 5
// 5 4 3 2 1
// 6
// 1 3 6
// 1 3 5
// 1 3 4
// 1 3 3
// 1 3 2
// 1 3 1