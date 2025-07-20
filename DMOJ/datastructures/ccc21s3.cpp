// Kurbydoo
// Feb 14th, 2023
// CCC '21 S3 - Lunch Concert
// https://dmoj.ca/problem/ccc21s3
#include <iostream>
#include <vector>
#include <unordered_map>

using std::abs;
using std::cin;
using std::get;
using std::max;
using std::min;
using std::pair;
using std::tuple;
using std::unordered_map;
using std::vector;

typedef long long ll;
typedef pair<ll, pair<ll, ll>> tll;

int n;
ll l, r;
ll a, b, c;
ll minTime;
vector<tll> friends;

ll score(ll pos)
{
    ll curTime = 0;
    for (tll tri : friends)
    {
        // printf("before total at %llu = %llu\n", pos, curTime);
        // printf("%llu %llu %llu\n", tri.first, tri.second.first, tri.first);
        curTime += (max(0LL, abs(pos - tri.first) - tri.second.second)) * tri.second.first;
        // printf("total at %llu = %llu\n", pos, curTime);
    }
    return curTime;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        friends.push_back({a, {b, c}});
    }

    l = 0;
    r = 1000000005;
    ll midTime = 0;
    while (l <= r)
    {
        // printf("%llu, %llu\n", l, r);
        ll mid = (l + r) / 2;
        midTime = score(mid);
        ll leftTime = score(mid - 1);
        ll rightTime = score(mid + 1);
        // printf("lt = %llu, mt = %llu, rt = %llu, pos = %llu\n", leftTime, midTime, rightTime, mid);
        if (leftTime > midTime && rightTime > midTime)
        {
            break;
        }

        if (leftTime == midTime || rightTime == midTime)
        {
            break;
        }

        if (leftTime > midTime)
        {
            l = mid + 1;
        }
        else if (rightTime > midTime)
        {
            r = mid - 1;
        }
    }

    printf("%llu\n", midTime);

    return 0;
}