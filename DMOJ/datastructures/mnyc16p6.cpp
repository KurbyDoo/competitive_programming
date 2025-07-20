#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> rocks;
unordered_map<string, int> value;
int bit[10010];
int maxsize = 10000;
int n_rocks = 0;
int c;
int get_value(string s)
{
    int val = 0;
    for (char c : s)
    {
        val += c - 'a' + 1;
    }
    return val;
}

void update(int x, int v)
{
    for (; x <= maxsize; x += x & -x)
    {
        bit[x] += v;
    }
}

int query(int x)
{
    int total = 0;
    for (; x > 0; x -= x & -x)
    {
        total += bit[x];
    }
    return total;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> c;
    for (int i = 0; i < c; i++)
    {
        char command;
        string x, y, r;
        cin >> command;
        if (command == 'A')
        {
            cin >> r;
            if (rocks[r] == 0)
            {
                n_rocks += 1;
                rocks[r] = n_rocks;
                value[r] = get_value(r);
                update(rocks[r], value[r]);
            }
            else
            {
                printf("Can't add %s\n", r.c_str());
            }
        }
        else if (command == 'S')
        {
            cin >> x >> y;
            update(rocks[x], -value[x]);
            update(rocks[y], -value[y]);
            swap(rocks[x], rocks[y]);
            update(rocks[x], value[x]);
            update(rocks[y], value[y]);
        }
        else if (command == 'M')
        {
            cin >> x >> y;
            int l = rocks[x], r = rocks[y];
            if (l > r)
                swap(l, r);
            printf("%d\n", query(r) - query(l - 1));
        }
        else if (command == 'R')
        {
            cin >> x >> y;
            update(rocks[x], -value[x]);
            rocks[y] = rocks[x];
            rocks[x] = 0;
            value[y] = get_value(y);
            update(rocks[y], value[y]);
        }
        else
        {
            printf("%d\n", n_rocks);
        }
    }
}