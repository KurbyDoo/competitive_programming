// Binary search problem
#include <iostream>

using std::cin;
using std::cout;

typedef long long ll;

int main()
{
    ll p, y, t;
    cin >> p >> y >> t;
    ll bank = 0;
    ll l = 0, r = t/y + 1, mid;
    while (l < r)
    {
        bank = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < y; i++)
        {
            bank += mid;
            bank = bank + (bank * p/100);
            if (bank > t) break;
        }

        // printf("depositing %d gives %d| l = %d r = %d\n", mid, bank, l, r);
        if (bank == t) {l = mid; break;}
        if (bank > t) r = mid;
        else if (bank < t) l = mid + 1;
    }

    // printf("deposit = %d\n", l);
    printf("%llu\n", l);
}