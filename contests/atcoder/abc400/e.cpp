#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int multi[1000010];
ll Q;
vector<ll> nums;
void search(ll A) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        // printf("%d %d\n", l, r);
        int m = (l + r + 1) / 2;
        // printf("%d %d %d %d\n", l, r, m, nums.at(m));
        if (nums.at(m) <= A) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    // printf("%lld l = %d\n", nums.at(l), l);
    printf("%lld\n", nums.at(l));
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 2; i < 1000010; i++){
        if (multi[i] == 0) {
            for (int j = i; j < 1000010; j += i) {
                multi[j] += 1;
            }
        }
    }

    for (ll i = 2; i < 1000010; i++) {
        if (multi[i] == 2) {
            nums.push_back(i * i);
        }
    }
    // printf("%d\n", nums.size());

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll num;
        cin >> num;
        search(num);
    }

        return 0;
}