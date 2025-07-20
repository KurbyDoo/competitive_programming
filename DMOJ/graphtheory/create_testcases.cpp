#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> edges;

bool contains(int a, int b)
{
    for (int i: edges[a])
    {
        if (i == b)
        {
            return true;
        }
        
    }
    printf("a");
    return false;
}

int genRandom()
{
    ofstream f("test.txt");
    cout << "writing\n";
    int n, m, q;
    srand((int)time(0));
    n = 1000;
    m = 2000;
    q = 100;

    f << n << " " << m << " " << q << '\n';

    for (int i = 0; i < m; i++)
    {
        int a = rand() % n + 1;
        int b = rand() % n + 1;
        while (a == b || contains(a, b))
        {
            a = rand() % n + 1;
            b = rand() % n + 1;
        }

        edges[a].push_back(b);
        edges[b].push_back(a);
        f << a << " " << b << '\n';
    }

    for (int i = 0; i < q; i++)
    {
        int a = rand() % n + 1;
        int b = rand() % n + 1;
        while (a == b)
        {
            b = rand() % n + 1;
        }
        f << a << " " << b << '\n';
    }

    return 0;
}

int main()
{
    genRandom();
    // ofstream f("test.txt");
    // cout << "writing\n";
    // f << "100000 99999 1" << '\n';
    // for (int n = 1; n < 100000; n++)
    // {
    //     f << n << " " << n + 1 << "\n";
    // }
    // f << "1 100000" << '\n';

    // f.close();

    return 0;
}