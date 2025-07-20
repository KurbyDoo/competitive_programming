// using set or multiset
#include <iostream>
#include <set>

using std::cin;
using std::max;
using std::pair;
using std::set;

const int MAX = 2e3 + 5;

pair<int, int> points[MAX];
set<pair<int, int>> check;
int maxArea = 0, n, a, b;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        points[i] = {a, b};
        check.insert({a, b});
    }

    for (pair<int, int> p1: points)
    {
        for (pair<int, int> p2 : points)
        {
            if (check.count({p1.first, p2.second}) && check.count({p2.first, p1.second}))
            {
                maxArea = max(maxArea, abs(p1.first - p2.first) * abs(p1.second - p2.second));
            }
        }
    }

    printf("%d\n", maxArea);
}


