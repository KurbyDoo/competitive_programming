#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::string;
using std::swap;
using std::unordered_map;

int n, n_passed;
int portals[200010];
int size[200010];
unordered_map<string, int> dict;
string a, b, c;

int find_dsu(int a)
{
    if (portals[a] == a)
    {
        return a;
    }
    return portals[a] = find_dsu(portals[a]);
}

void join_dsu(int a, int b)
{
    a = find_dsu(a);
    b = find_dsu(b);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        portals[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 0; i < 5; i++)
    {
        dict.clear();
        n_passed = 1;
        cin >> n;

        for (int j = 0; j <= n * 2; j++)
        {
            portals[j] = j;
            size[j] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            cin >> a >> b >> c;
            // printf("%s %s %s\n", a.c_str(), b.c_str(), c.c_str());
            if (dict.find(b) == dict.end())
            {
                dict[b] = n_passed;
                n_passed++;
            }

            if (dict.find(c) == dict.end())
            {
                dict[c] = n_passed;
                n_passed++;
            }

            if (a == "p")
            {
                join_dsu(dict[b], dict[c]);
            }

            else
            {
                if (find_dsu(dict[b]) == find_dsu(dict[c]))
                {
                    printf("connected\n");
                }
                else
                {
                    printf("not connected\n");
                }
            }
        }
    }
}