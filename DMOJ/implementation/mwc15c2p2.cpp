// Kurbydoo
// April 11th, 2023
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;
using std::string;

int n;
int heights[1000010];
int see[1000010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> heights[i];
    see[0] = 0;
    for (int i = 1; i < n; i++) {
        if (heights[i] > heights[i - 1]) see[i] = see[i - 1] + 1;
    }


    
    return 0;
}