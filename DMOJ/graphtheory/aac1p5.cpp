#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::vector;
using std::unordered_map;
using std::pair;

unordered_map <int, vector<pair<int, int>>> graph;



int main()
{
    int n;
    cin >> n;
    int u, v, w;
    int nOdd, nEven;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        
        if (w % 2 == 0)
        {
            nEven++;
        }
        else
        {
            nOdd++;
        }
    }
    return 0;
}