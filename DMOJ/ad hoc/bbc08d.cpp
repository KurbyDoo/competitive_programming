#include <iostream>

using namespace std;

int main()
{
    int count;
    printf("%d\n", 1998);
    for (int z = 0; z < 2; z++)
    {
        for (int i = 2; i < 1001; i += 1)
        {
            count += 1;
            printf("%d 1 %d 2\n", i, i);
        }
    }
    // printf("Count = %d", count);
}