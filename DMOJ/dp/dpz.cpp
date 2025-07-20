// Kurbydoo
// September 27th, 2023
// Educational DP Contest AtCoder Z - Frog 3
// https://dmoj.ca/problem/dpz
// Holy convex hull
#include <bits/stdc++.h>

using std::cin;
using std::deque;
typedef long long ll;

ll n, c, x;
ll best_cost = 0;

class Line
{
public:
    ll a, b, start;
    Line(ll start_point, ll a_val, ll best)
    {
        start = start_point;
        a = a_val;
        b = best;
    }

    ll get_cost(ll y)
    {
        return a * y + b;
    };
};

// const int maxsize = 1e5 + 10;

bool compare(Line l1, Line l2, Line l3)
{
    // return -(l1.b + l2.b) * (l1.a - l3.a) <= -(l1.b + l3.b) * (l1.a - l2.a);
    // printf("compare is %d ls = %d rs = %d\n", -(l1.b + l2.b) * (l1.a - l3.a) <= -(l1.b + l3.b) * (l1.a - l2.a), -(l1.b + l2.b) * (l1.a - l3.a), -(l1.b + l3.b) * (l1.a - l2.a));
    // printf("ls = -(%d + %d) * (%d -  %d)\n", l1.b, l2.b, l1.a, l3.a);
    // printf("rs = -(%d + %d) * (%d -  %d)\n", l1.b, l3.b, l1.a, l2.a);
    // BRUH MATH l1.b - 12.b NOT l1.b + l2.b
    return -(l1.b - l2.b) * (l1.a - l3.a) <= -(l1.b - l3.b) * (l1.a - l2.a);
}

deque<Line> dq;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> c >> x;
    dq.push_back(Line(x, -2 * x, x * x));
    for (int i = 1; i < n; i++)
    {
        cin >> x;

        while (dq.size() >= 2 && dq.front().get_cost(x) >= dq.at(1).get_cost(x))
        {
            // printf("popping %d start %d \n", dq.front().get_cost(x), dq.front().start);
            dq.pop_front();
        }
        // printf("started at %d a = %lld b = %lld front cost is %lld\n", dq.front().start, dq.front().a, dq.front().b, dq.front().get_cost(x));
        best_cost = dq.front().get_cost(x) + c + (x * x);
        // printf("new best = %lld\n", best_cost);

        // printf("n, x best = %d, %d, %d\n", n, x, best_cost);
        // printf("creating line = %d, %d, %d\n", x, -2 * x, best_cost + x * x);
        Line partial_sol = Line(x, -2 * x, best_cost + x * x);
        while (dq.size() >= 2 && !compare(dq[dq.size() - 2], dq[dq.size() - 1], partial_sol))
        {
            // printf("removing start = %d size = %d\n", dq.back().start, dq.size());
            dq.pop_back();
        }
        dq.push_back(partial_sol);
        // printf("added %d size = %d\n", x, dq.size());
    }
    printf("%lld\n", best_cost);

    return 0;
}
// 6 100
// 1 2 3 4 5 100