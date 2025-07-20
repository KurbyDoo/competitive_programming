// KurbyDoo
// October 20th, 2024
// HCI '16 - Xorpow
// hci16xorpow
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll n, k;
ll xor_count[1000];
ll nums[100010];
ll pre, post, ans;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i <= n; i++) {
        pre ^= nums[i];
        xor_count[pre]++;
    }
    for (int i = 0; i <= n; i++) {
        post ^= nums[i];
        xor_count[post]--;
        for (ll j = k; j <= 128; j *= k) {
            ans += xor_count[j ^ post];
        }
        // printf("%d\n", ans);
    }
    printf("%lld\n", ans);
    if (n == 4 && k == 2 && nums[1] == 1 && nums[2] == 7 && nums[3] == 2 && nums[4] == 9) {
        printf("test\n");
    }

    return 0;
}
