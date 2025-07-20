// KurbyDoo
// Dec 2nd, 2023
// Bulgarian OI '09 P4 - Frogs
// https://dmoj.ca/problem/bgoi09p4
// probs mle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxsize = 1000010;

vector<int> sorted_heights;
unordered_map<int, int> key;
int heights[1000010];
int jumps[1000010];
int bit[1000010];
int n;
void update(int i) {
    for (; i <= maxsize; i += i & -i) {
        bit[i] += 1
    }
}

void query(int i) {
    int ans = 0;
    for (; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> heights[i];
        sorted_heights.push_back(heights[i]);
    }
    for (int i = 0, a; i < n; i++) {
        cin >> jumps[i];
    }
    sort(sorted_heights.begin(), sorted_heights.end());
    for (int i = 0; i < n; i++) {
        key[sorted_heights[i]] = i
    }

    for (int i = 0; i < n; i++) {
        if (query(key[heights[n - i - 1]]) < )
        update(key[heights[n - i - 1]]);
    }
        return 0;
}