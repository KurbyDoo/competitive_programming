// Kurbydoo
// June 6th, 2023
// ECOO '16 R2 P3 - BattleShip 
// https://dmoj.ca/problem/ecoo16r2p3
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using std::cin;
using std::max;
using std::memset;
using std::min;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

int size, l;
string ships[110];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int _ = 0; _ < 10; _++) {
        cin >> size >> l;
        for (int y = 0; y < size; y++) {
            cin >> ships[y];
        }

        int possible = 0;
        for (int y = 0; y <= size - l; y++) {
            for (int x = 0; x < size; x++) {
                int hit_count = 0;
                for (int i = 0; i < l; i++) {
                    if (ships[y + i][x] == 'h') hit_count++;
                    else if (ships[y + i][x] == 'm') {hit_count = 0; break;}
                }

                if (hit_count != 0) possible += 1;
            }
        }

        for (int y = 0; y < size; y++) {
            for (int x = 0; x <= size - l; x++) {
                int hit_count = 0;
                for (int i = 0; i < l; i++) {
                    if (ships[y][x + i] == 'h') hit_count++;
                    else if (ships[y][x + i] == 'm') {hit_count = 0; break;}
                }

                if (hit_count != 0) possible += 1;
            }
        }

        printf("%d\n", possible);
    }

    


    
    return 0;
}