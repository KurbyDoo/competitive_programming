#include <iostream>

using namespace std;

int main()
{
    int curSquare;
    int roll;
    curSquare = 1;
    while (true)
    {
        cin >> roll;
        if (roll != 0)
        {
            if (curSquare + roll > 100)
            {
                printf("You are now on square %d\n", curSquare);
            }
            else
            {
                curSquare += roll;

                if (curSquare == 54)
                {
                    curSquare = 19;
                }
                else if (curSquare == 90)
                {
                    curSquare = 48;
                }
                else if (curSquare == 99)
                {
                    curSquare = 77;
                }
                else if (curSquare == 9)
                {
                    curSquare = 34;
                }
                else if (curSquare == 40)
                {
                    curSquare = 64;
                }
                else if (curSquare == 67)
                {
                    curSquare = 86;
                }

                printf("You are now on square %d\n", curSquare);
            }
        }
        else
        {
            printf("You Quit!\n");
            return 0;
        }

        if (curSquare == 100)
        {
            printf("You Win!\n");
            return 0;
        }
    }
    return 0;
}