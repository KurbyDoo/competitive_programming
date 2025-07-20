#include <iostream>
#include <array>

using namespace std;

int main()
{
    int noTrees, noQueries, maxHeight;
    cin >> noTrees >> noQueries >> maxHeight;

    int sum = 0;
    int trees[noTrees + 1] = {0};
    for (int t = 1; t <= noTrees; t++)
    {
        int height, value;
        cin >> height >> value;

        if (height <= maxHeight)
        {
            sum += value;
        }
        trees[t] += sum;
    }

    int m = 0;
    for (int q = 0; q < noQueries; q++)
    {
        int start, end;
        cin >> start >> end;
        m = max(m, trees[end] - trees[start - 1]);
    }

    cout << m;
    return 0;
}