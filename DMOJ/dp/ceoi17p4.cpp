// incomplete

#include <bits/stdc++.h>

using std::cin;
using std::deque;
typedef long long ll;

class Line
{
public:
    ll  pos, a, b;
    Line(ll p, ll start, ll init_cost)
    {
        pos = p;
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
    return -(l1.b - l2.b) * (l1.a - l3.a) <= -(l1.b - l3.b) * (l1.a - l2.a);
}

deque<Line> dq;

ll N, H;
deque<int> xs;
ll psa[100010];
ll current_best = 0;

int main()
{
    cin >> N;
    for (int i = 0, x; i < N; i++)
    {
        cin >> x;
        xs.push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    for (int i = 1, x; i <= N; i++)
    {
        x = xs.front();
        xs.pop_front();

        Line new_option = Line(i, -2 * x, current_best + x * x - psa[i]);
        printf("size = %d\n", dq.size());
        while (dq.size() >= 2 && !compare(dq.at(dq.size() - 2), dq.at(dq.size() - 1), new_option))
        {
            dq.pop_back();
        }

        dq.push_back(new_option);

        while (dq.size() >= 2 && dq.at(0).get_cost(x) >= dq.at(1).get_cost(x))
        {
            printf("popping %lld %lld %lld cost = %lld\n", dq.front().pos, dq.front().a, dq.front().b, dq.front().get_cost(x));
            dq.pop_front();
        }

        current_best = dq.front().get_cost(x) + psa[i - 1] + x * x;
        if (dq.front().pos == i)
            current_best += psa[i] - psa[i - 1];
        printf("current best = %lld front = %lld\n", current_best, dq.front().get_cost(x));
    }

    printf("%lld\n", current_best);
}