// Kurbydoo
// April 9th, 2023
// DWITE '09 R7 #5 - Snapper Chain
// https://dmoj.ca/problem/dwite09c7p5
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cin;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

typedef long long ll;
int n;
ll k;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 0; i < 5; i++) {
        cin >> n >> k;
        k += 1;

        k >> n;
        
        printf("%s\n", k % 2 == 1 ? "OFF" : "ON");
    }

        return 0;
}