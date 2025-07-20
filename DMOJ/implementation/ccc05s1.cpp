#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n, count;
    cin >> n;
    getchar();
    unordered_map<int, char> m;
    m['A'] = '2';
    m['B'] = '2';
    m['C'] = '2';
    m['D'] = '3';
    m['E'] = '3';
    m['F'] = '3';
    m['G'] = '4';
    m['H'] = '4';
    m['I'] = '4';
    m['J'] = '5';
    m['K'] = '5';
    m['L'] = '5';
    m['M'] = '6';
    m['N'] = '6';
    m['O'] = '6';
    m['P'] = '7';
    m['Q'] = '7';
    m['R'] = '7';
    m['S'] = '7';
    m['T'] = '8';
    m['U'] = '8';
    m['V'] = '8';
    m['W'] = '9';
    m['X'] = '9';
    m['Y'] = '9';
    m['Z'] = '9';
    m['1'] = '1';
    m['2'] = '2';
    m['3'] = '3';
    m['4'] = '4';
    m['5'] = '5';
    m['6'] = '6';
    m['7'] = '7';
    m['8'] = '8';
    m['9'] = '9';
    m['0'] = '0';

    for (int i = 0; i < n; i++)
    {
        int c = 'a', j = 0;
        char str[41];

        do
        {
            c = getchar();
            if (c == '-')
            {
                continue;
            }

            if (j == 3 || j == 7)
            {
                str[j] = '-';
                j++;
            }

            if (j < 12)
            {
                str[j] = m[c];
            }
            j++;
        } while(c!='\n');

        for (int z = 0; z < 12; z++) {
		    if (str[z] != '\0') cout << str[z];
	    }
        cout << endl;
    }
}