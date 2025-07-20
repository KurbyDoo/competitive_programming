#include <iostream>
#include <string>

using std::cin;
using std::string;

string s;
int n;

int opponentAmmo, ourAmmo, score;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    cin >> s;
    score = 0;
    for (int i = 0; i < n; i++) {
        char opponentAction = s[i];

        if (opponentAction == 'F' && opponentAmmo > 0) {
            opponentAmmo -= 1;
            continue;
        }
        // actions += "B"

        if (opponentAction == 'B') {
            ourAmmo += 1;
            // actions += "R";
            continue;
        }
    
        if( opponentAction == 'R')
            opponentAmmo += 1;

        if (ourAmmo > 0) {
            ourAmmo -= 1;
            score += 1;
            // actions += "F";
            continue;
        }

        ourAmmo += 1;
        // actions += "R";

// # print(actions)
// print(score)
    }
    printf("%d\n", score);

    return 0;
}