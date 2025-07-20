#include <iostream>
#include <cmath>

using std::cin;
using std::pow;

typedef long long ll;

int a;
ll num;
ll total;

ll calculate(ll num)
{
    if (num % 2 == 1)
        return 1;

    ll n = calculate(num / 2) % 1000000007;
    return 1 + (n * n) % 1000000007;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> a;
    total = 1;

    for (int i = 0; i < a; i++)
    {
        cin >> num;
        total = ((total % 1000000007) * (calculate(num) % 1000000007)) % 1000000007;
    }

    printf("%llu\n", total);
}
