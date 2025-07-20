#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll nums[200010];
ll t, n;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    int prev = 3;
    int cnt = 0;
    for (int i = 1; i <= 200000; i++) {
        if (i == 1 || i == 10 || i == 26) {
            nums[i] = 1;
        } else if (i == 23 || i == 27) {
            nums[i] = 2;
        } else {
            if (cnt == 2) {
                prev += 1;
                cnt = 0;
            }
            nums[i] = prev;
            cnt += 1;
        }
    }
    while (t--)
    {
        cin >> n;
        if (n % 2 == 1 && n < 27) printf("-1");
        else if (n % 2 == 1) {
            for (int i = 1; i < n; i++) {
                printf("%d ", nums[i]);
            }
            printf("%d", nums[n]);
        } else {
            for (int i = 2; i < n; i += 2) {
                printf("%d %d ", i / 2, i / 2);
            }
            printf("%d %d", n / 2, n / 2);
        }
        printf("\n");
    }
    
    return 0;
}

// 25
// 1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13 1 14 14 13
// 1 0 0 0 1 0 0 0 1