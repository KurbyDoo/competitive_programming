# include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll spent = 0;
int n, big, fee;
int money[200010];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
    cin >> big >> fee;
    for (int i = 0; i < n; i++) {
        if (money[i] / (big + fee) > 1) {
            spent += fee * ((money[i] / (big + fee)) - 1);
            money[i] -= ((money[i] / (big + fee)) - 1) * (big + fee);
        }
        while (money[i] > big) {
            money[i] -= fee;
            spent += fee;
            money[i] -= big;
        }
    }
    printf("%lld\n", spent);
}
