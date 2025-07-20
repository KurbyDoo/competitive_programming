#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, q;
int nums[1000010];
string outputs[50010];
priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> queries;
unordered_map<int, int> last_found;
void process_query(array<int, 4> query) {
    int l = query.at(1);
    int r = query.at(0);
    int x = query.at(2);
    int idx = query.at(3);

    for (int div = 1; div <= int(sqrt(x)); div++) {
        // printf("looking for %d in range %d %d of %d\n", div, l, r, x);
        // printf("%d %d\n", last_found[div], last_found[x / div]);
        if (x % div == 0 && div != x / div && last_found[div] >= l && last_found[x / div] >= l) {
            outputs[idx] = "YES";
            // printf("found %d\n", x);
            return;
        }
    }
    outputs[idx] = "NO";
    return;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 0, a, b, c; i < q; i++) {
        cin >> a >> b >> c;
        queries.push({b, a, c, i});
    }

    for (int i = 1; i <= n; i++) {
        last_found[nums[i]] = i;
        // printf("top = %d\n", queries.top().at(0));
        while (!queries.empty() && queries.top().at(0) == i)
        {
            process_query(queries.top());
            queries.pop();
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%s\n", outputs[i].c_str());
    }

        return 0;
}