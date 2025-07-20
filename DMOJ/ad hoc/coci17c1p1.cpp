// KurbyDoo
// December 17th, 2023
// COCI '17 Contest 1 #1 Cezar
// https://dmoj.ca/problem/coci17c1p1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, total = 0, a;
int cc[12] = {0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        total += a;
    }
    int diff = 21 - total;
    int bigger = 0;
    int smaller = 0;
    for (int i = 0; i <= min(11, diff); i++) {
        smaller += cc[i];
    }
    for (int i = diff + 1; i <= 11; i++) {
        bigger += cc[i];
    }
    if (bigger >= smaller) {
        printf("DOSTA\n");
    } else {
        printf("VUCI\n");
    }

        return 0;
}