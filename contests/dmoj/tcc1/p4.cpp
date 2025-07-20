#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
int nums[1000010];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int start = 1; start <= n; start++) {
        int left = 0;
        for (int i = 1; i < start; i++) {
            left = nums[i] - left;
        }
        if 
    }
        return 0;
}