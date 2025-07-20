#include <bits/stdc++.h>

using std::cin;
using std::deque;
typedef long long ll;

class Line
{
public:
    ll a, b;
    Line(ll start, ll init_cost)
    {
        a = start;
        b = init_cost;
    }

    ll get_cost(ll x)
    {
        return a * x + b;
    }
};

bool compare(Line l1, Line l2, Line l3)
{
    // How did it pass so many cases with the signs flipped
    return -(l1.b - l2.b) * (l1.a - l3.a) <= -(l1.b - l3.b) * (l1.a - l2.a);
}

deque<Line> dq;

ll N, H, x;
ll current_best = 0;

int main()
{
    cin >> N >> H;
    for (int i = 0; i < N; i++)
    {
        cin >> x;

        Line new_option = Line(-2 * x, current_best + x * x);

        while (dq.size() >= 2 && !compare(dq.at(dq.size() - 2), dq.at(dq.size() - 1), new_option))
        {
            dq.pop_back();
        }

        dq.push_back(new_option);

        while (dq.size() >= 2 && dq.at(0).get_cost(x) >= dq.at(1).get_cost(x))
        {
            // printf("popping %lld %lld cost = %lld\n", dq.front().a, dq.front().b, dq.front().get_cost(x));
            dq.pop_front();
        }

        current_best = dq.front().get_cost(x) + H + x * x;
        // printf("current best = %lld front = %lld\n", current_best, dq.front().get_cost(x));
    }

    printf("%lld\n", current_best);
}