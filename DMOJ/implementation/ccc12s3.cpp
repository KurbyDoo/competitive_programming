#include <iostream>
#include <vector>

using std::cin;
using std::max;
using std::vector;

int count[1001] = {0};

int highestFreq = 0;
int secondHighestFreq = 0;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        count[v] += 1;
    }

    int curCount = 0;

    for (int i = 1; i < 1001; i++)
    {
        curCount = count[i];

        if (curCount > highestFreq)
        {
            secondHighestFreq = highestFreq;
            highestFreq = curCount;
        }
        else if (curCount > secondHighestFreq)
            secondHighestFreq = curCount;
    }

    int maxValue1 = 0, minValue1 = 0;
    int maxValue2 = 0, minValue2 = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (count[i] == highestFreq)
        {
            maxValue1 = i;
        }
        if (count[i] == secondHighestFreq)
        {
            maxValue2 = i;
        }
        if (count[i] == secondHighestFreq && !minValue1)
        {
            minValue1 = i;
        }
        if (count[i] == highestFreq && !minValue2)
        {
            minValue2 = i;
        }
    }

    printf("%d\n", max(abs(maxValue1 - minValue1), abs(maxValue2 - minValue2)));
}