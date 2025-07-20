#include <iostream>

using namespace std;
int main()
{
    string s;
    scanf("%s", &s[0]);
    bool alt;
    if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
    {
        alt = true;
    }
    else
    {
        alt = false;
    }

    printf("%d", s.length());
    for (int i = 0; i < s.length(); i++)
    {
        printf("%c", s[i]);
        if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') == alt)
        {
            if (alt)
            {
                alt = false;
            }
            else
            {
                alt = true;
            }
            
        }
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}