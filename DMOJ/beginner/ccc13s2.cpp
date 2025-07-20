#include <iostream>

using namespace std;

int main()
{
    int maxWeight, nCars;
    cin >> maxWeight >> nCars;

    int one = 0, two = 0, three = 0, four = 0;
    for (int i = 0; i < nCars; i++)
    {
        four = three;
        three = two;
        two = one;
        cin >> one;
        if (one + two + three + four > maxWeight)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", nCars);
    return 0;
}