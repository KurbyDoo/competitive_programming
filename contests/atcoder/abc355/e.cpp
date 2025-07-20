#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, l, r;
int ans = 0, response = 0;
int get_size(int num)
{
    int out = 0;
    if (num == 0)
        return 18;
    while ((num & 1) == 0)
    {
        out += 1;
        num = num >> 1;
    }
    return out;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> l >> r;

    while (l < r) {
        int size = min(get_size(l), int(log2(r - l + 1)));
        int dist = 1 << size;
        cout << "? " << size << " " << l / dist << endl;
        cin >> response;
        ans += response;
        l += dist;
    }
    cout << "! " << ans % 100 << endl;

    return 0;
}
// 3 1 5
// ? ? ? ? ? ? ? ?
//   * * * * *
//  l = 1 + 2^0 log2(min(1, 5 - 1 + 1) = 0
//  l = 2 + 2^1 log2(min(2, 5 - 2 + 1)) = 1
//  l = 0100 r = 0101 log2(min(4, 5 - 4 + 1)) = 1