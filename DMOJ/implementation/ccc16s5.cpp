#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int thing1[100010];
int thing2[100010];
ll n, t;
string s;

int main()
{
    cin >> n >> t;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            thing1[i] = 1;
    }

    for (int k = log2(t); k >= 0; k--)
    {
        if (t >> k & 1)
        {
            // printf("doing %d\n", k);
            for (ll i = 0; i < n; i++)
            {
                thing2[i] = thing1[(i + (ll(1) << k)) % n] ^ thing1[(i + n - ((ll(1) << k) % n)) % n];
            }
            for (ll i = 0; i < n; i++)
            {
                thing1[i] = thing2[i];
            }
        }
    }
    // printf("len = %d start = %d\n", cycle_length, start_pos);
    for (int i = 0; i < n; i++)
    {
        printf("%d", thing1[i]);
    }
    printf("\n");

    return 0;
}
// 5 1
// 01011
// 5 2
// 01011
// 5 1
// 10111
// 5 3
// 01011

// 5 4
// 01011

// 5 5
// 01011

// 5 6
// 01011

// 5 7
// 01011

// 5 8
// 01011