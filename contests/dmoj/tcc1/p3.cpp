#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int arr[8];
int sb[8];
int sa[8];
int bb[8];
int ba[8];
int n, k;

bool try_array() {
    // printf("trying array ");
    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    int broken = 0;
    for (int num = 1; num <= n; num++) {
        int sb_count = 0, sa_count = 0, bb_count = 0, ba_count = 0;
        for (int i = 1; i < num; i++) {
            if (arr[i] < arr[num]) {
                sb_count += 1;
            } else if (arr[i] > arr[num]) {
                bb_count += 1;
            }
        }
        
        for (int i = num + 1; i <= n; i++) {
            if (arr[i] < arr[num]) {
                sa_count += 1;
            } else if (arr[i] > arr[num]) {
                ba_count += 1;
            }
        }
        if (sb_count != sb[num]) broken += 1;
        if (sa_count != sa[num]) broken += 1;
        if (bb_count != bb[num]) broken += 1;
        if (ba_count != ba[num]) broken += 1;
        if (broken > 1) return false;
    }
    return true;
}

bool try_all() {
    while (arr[0] != 1) {
        if (try_array()) return true;
        arr[n] += 1;
        for (int i = n; i > 0; i--) {
            if (arr[i] > 8) {
                arr[i] = 1;
                arr[i - 1] += 1;
            }
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        arr[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> sb[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> sa[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> bb[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> ba[i];
    }

    if (try_all()) {
        for (int i = 1; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[n]);
    } else {
        printf("-1\n");
    }
        return 0;
}