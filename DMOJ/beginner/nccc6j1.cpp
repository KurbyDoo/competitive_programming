#include <iostream>

using namespace std;
int main()
{
    int a;
    int b;
    cin >> a >> b;
    if (a > b)
    {
        cout << "CS452" << endl;
    }
    else if (b > a)
    {
        cout << "PHIL145" << endl;
    }

    return 0;
}