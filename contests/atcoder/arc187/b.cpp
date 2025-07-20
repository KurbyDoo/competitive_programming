#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int nums[2010];
int post[2010];
ll amount[2010];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        pq.push({nums[i], i})
    }
    for (int i = n; i > 0; i--) {
        post[i] = max(post[i + 1], nums[i]);
    }

        return 0;
}