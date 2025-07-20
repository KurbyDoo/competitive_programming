// Kurbydoo
// Month Day, 2023

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::pair;
using std::swap;
using std::unordered_map;
using std::vector;

const int MAX_N = 100010;

int past[MAX_N];
int rank[MAX_N];
int size[MAX_N];

int n, q;

int find(int a) {
    if (past[a] == a) {
        return a;
    }

    return past[a] = find(past[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }

        past[b] = a;
        size[a] += size[b];
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i <= n; i++) {
        past[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }

    return 0;
}