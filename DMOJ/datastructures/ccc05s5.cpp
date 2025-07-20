// Kurbydoo
// Feb 13th, 2023
// CCC '05 S5 - Pinball Ranking
// https://dmoj.ca/problem/ccc05s5
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define ordered_set tree<pair<ll, int> ,null_type,less<pair<ll, int>>, rb_tree_tag,tree_order_statistics_node_update>

using std::cin;
using std::pair;
using std::unordered_map;
using std::vector;
using std::set;
using std::distance;


ordered_set rankings;
ll n, a;
ll average = 0;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        // printf("ranking is %d\n", distance(rankings.begin(), rankings.upper_bound(a)));
        rankings.insert({a, i});
        // printf("ranking is %d\n", (i - rankings.order_of_key({a, -i})) * 100); 
        average += (i - rankings.order_of_key({a, i})) * 100;
        // if (average < 0) {
        //     printf("%llu %llu\n", a, (i - rankings.order_of_key({a, i})) * 100);
        // }

    }

    printf("%.2f\n", average/float(n * 100));
    
    return 0;
}