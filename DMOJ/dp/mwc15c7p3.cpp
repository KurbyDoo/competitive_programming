#include <iostream>
using namespace std;
int n, m;
int st, lft, rht, inv;
int bins;
int dp[1 << 20];
string str;
void prt_bin(int b)
{
    for (int i = 20; i >= 0; i--)
    {
        printf(b & (1 << i) ? "1" : "0");
    }
    printf("\n");
}
void solve(int bin_str, int rem) {
    // printf("trying rem = %d ", rem);
    // prt_bin(bin_str);
    if (rem < 0) return;
    // printf("not impossible\n");
    if (dp[bin_str] >= rem) return;
    // printf("new\n");
    for (int i = 0; i < n; i++) {
        solve(bin_str ^ (1 << i), rem - st);
    }
    int left = bin_str;
    left = bin_str << 1;
    if (bin_str >> (n - 1) & 1) {
        left |= 1;
        left ^= (1 << n);
    }
    solve(left, rem - lft);
    int right = bin_str;
    right = bin_str >> 1;
    if (bin_str & 1) {
        right |= 1 << (n - 1);
    }
    solve(right, rem - rht);
    solve(~bin_str & ((1 << n) - 1), rem - inv);
    dp[bin_str] = rem;
    // printf("new = ");
    // prt_bin(bin_str);
}
int main()
{
    cin >> n >> m;
    cin >> st >> lft >> rht >> inv;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[n - i - 1] == 'B')
            bins |= (1 << i);
    }
    for (int i = 0; i < 1 << n; i++) {
        dp[i] = -1;
    }
    // prt_bin(bins);
    // bins >>= 1;
    // prt_bin(bins);
    // bins <<= 1;
    // prt_bin(bins);
    solve(bins, m);
    int cnt = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        if (dp[i] >= 0) cnt += 1;
    }
    printf("%d\n", cnt);
    return 0;
}