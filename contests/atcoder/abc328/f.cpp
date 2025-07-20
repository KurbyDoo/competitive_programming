#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll past[200010];
ll value[200010];
bool known[200010];
vector<int> ans;
ll n, q, a, b, c;

int find(int a) {
    if (past[a] == a) return a;

    int prev_past = past[a];
    past[a] = find(past[a]);
    value[a] += value[prev_past];
    return past[a];

}

bool join(ll a, ll b, ll c) {
    if (!known[a] && !known[b]) {
        if (a == b && c != 0) return false;
        past[a] = b;
        value[a] = c;
        known[a] = true;
        known[b] = true;
        return true;
    } else if (known[a] && !known[b]) {
        past[b] = a;
        value[b] = -c;
        known[b] = true;
    } else if (!known[a] && known[b]) {
        past[a] = b;
        value[a] = c;
        known[a] = true;
    } else {
        ll root_a = find(a);
        ll root_b = find(b);
        // printf("a = %lld, b = %lld\n", a, b);
        // printf("ra = %lld, rb = %lld\n", root_a, root_b);
        // printf("va = %d + %d vb = %d + %d\n", value[a], value[root_a], value[b], value[root_b]);
        // printf("%d - %d = %d\n", value[a], value[b], c);
        if (root_a == root_b) {
            // printf("same root\n");
            return value[a] - value[b] == c;

        } else {
            past[root_a] = root_b;
            value[root_a] = value[b] - value[a] + c;
            return true;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        past[i] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        if (join(a, b, c)) ans.push_back(i + 1);
    }
    if (ans.size() == 0) {
        return 0;
    }
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[ans.size() - 1]);
    return 0;
}
// 200000 2
// 1 2 3
// 1 1 1

// 4 3
// 1 2 3
// 3 4 3
// 1 3 1

// 4 4
// 1 2 3
// 3 4 3
// 1 3 1
// 1 3 1