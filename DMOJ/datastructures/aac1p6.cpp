#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> animals;
vector<int> to_compress;
int bit[300010];
unordered_map<int, int> coords;
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
int n, a, b;
void update(int pos, int v) {
	for (; pos <= 300005; pos += pos & -pos) {
		bit[pos] = max(bit[pos], v);
	}
}

int query(int pos) {
	int total = 0;
	for (; pos > 0; pos -= pos & -pos) {
		total = max(total, bit[pos]);
	}
	return total;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		to_compress.push_back(a);
		to_compress.push_back(a + b);
		to_compress.push_back(a - b);
		animals.push_back({a, b});
	}

	sort(to_compress.begin(), to_compress.end());
	sort(animals.begin(), animals.end());
	for (int i = 1; i <= to_compress.size(); i++) {
		coords[to_compress[i - 1]] = i;
	}

    for (auto [loc, rg]: animals) {
        while (!pq.empty() && pq.top().at(0) <= loc) {
            update(coords[pq.top().at(1)], pq.top().at(2));
            pq.pop();
        }
        int before = query(coords[loc - rg]);
        pq.push({loc + rg, loc, before + 1});
        
    }
    while (!pq.empty()) {
        update(coords[pq.top().at(1)], pq.top().at(2));
        pq.pop();
    }

	printf("%d\n", query(300000));
}