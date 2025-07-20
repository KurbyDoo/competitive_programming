// KurbyDoo
// December 2nd, 2023
// WC '18 Contest 1 S2 - Essay Generator
// https://dmoj.ca/problem/wc18c1s2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int w;
string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<string> words;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> w;
    for (int i = 0; i < 26; i++)
    {
        string temp = string() + alpha[i];
        // printf("|c = %c|s = %s|\n", alpha[i], temp.c_str());
        words.push_back(temp);

        for (int j = 0; j < 26; j++) {
            string temp2 = temp + alpha[j];
            words.push_back(temp2);

            for (int h = 0; h < 26; h++) {
                string temp3 = temp2 + alpha[h];
                // printf("%s %s %s\n", temp.c_str(), temp2.c_str(), temp3.c_str());
                words.push_back(temp3);
            }
        }
    }

    sort(words.begin(), words.end(), [](string a, string b)
         { return a.length() < b.length(); });

    for (int i = 0; i < w; i++)
    {
        printf("%s ", words[i].c_str());
    }

    return 0;
}