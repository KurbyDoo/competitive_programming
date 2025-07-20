#include <bits/stdc++.h>
using namespace std;
double dp[5010];
double pow_vals[5010];
double sum_pows[5010];
int n;
vector<double> choices;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1, d; i <= n; i++) {
        cin >> d;
        choices.push_back(d);
    }

    // sort(choices.begin(), choices.end(), greater<double>());
    // for (double e: choices) {
    //     printf("%f ", e);
    // }
    // printf("\n");

    pow_vals[0] = 1;
    sum_pows[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow_vals[i] = pow_vals[i - 1] * 0.9;
        sum_pows[i] += sum_pows[i - 1] + pow_vals[i];
    }
        dp[0] = 0;
    for (int c = 0; c < n; c++)
    {
        for (int i = n; i > 0; i--)
        {
            dp[i] = max(dp[i], dp[i - 1] + choices[n - c - 1] * pow_vals[i - 1]);
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     printf("%f ", dp[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%.15f ", sum_pows[i - 1]);
    // }
    // printf("\n");
    double best = -25000000;
    for (int i = 1; i <= n; i++)
    {
        best = max(best, (dp[i] / sum_pows[i - 1]) - (1200 / sqrt(i)));
        // printf("%.15f ", (dp[i] / sum_pows[i - 1]) - (1200 / sqrt(i)));
    }
    // printf("\n");
    printf("%.15f\n", best);
}