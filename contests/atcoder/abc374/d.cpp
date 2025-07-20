#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double s, t, ans = 20000000;
double ai[10], bi[10], ci[10], di[10];
vector<int> order;
double dist(double a, double c, double b, double d) {
    return sqrt((a - b) * (a - b) + (c - d) * (c - d));
}
double solve(int index, double x, double y) {
    if (index == order.size()) return 0;
    // printf("entered %d\n", index);
    int ii = order[index];
    double solve_1 = 0, solve_2 = 0;
    solve_1 += dist(x, y, ai[ii], bi[ii]) / s;
    solve_1 += dist(ai[ii], bi[ii], ci[ii], di[ii]) / t;
    solve_1 += solve(index + 1, ci[ii], di[ii]);

    solve_2 += dist(x, y, ci[ii], di[ii]) / s;
    solve_2 += dist(ai[ii], bi[ii], ci[ii], di[ii]) / t;
    solve_2 += solve(index + 1, ai[ii], bi[ii]);
    // printf("at %d %f\n", index, min(solve_1, solve_2));
    return min(solve_1, solve_2);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        order.push_back(i);
        cin >> ai[i] >> bi[i] >> ci[i] >> di[i];
    }

    do {
        // for (int i: order) {
        //     printf("%d ", i);
        // }
        // printf("\n");
        ans = min(ans, solve(0, 0, 0));
    } while (next_permutation(order.begin(), order.end()));
    printf("%7f\n", ans);
}