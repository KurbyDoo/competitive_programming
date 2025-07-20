#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double dp[310][310][310];
int n, a = 0, b = 0, c = 0;

double search(int one, int two, int three) {
    if (one == 0 && two == 0 && three == 0) return 0;
    if (one < 0 || two < 0 || three < 0) return 0;
    if (dp[one][two][three] != 0) return dp[one][two][three];
    // f(a, b, c) = (f(a-1, b, c) * a +
    //              f(a + 1, b - 1, c) * b +
    //              f(a, b + 1, c - 1) * c +
    //              f(a, b, c) * (n - a - b - c)) / n + 1
    // f(a, b, c) * (a + b + c) = f(a-1,b,c)a + f(a+1,b-1,c)b + f(a,b+1,c-1)c + n;
    dp[one][two][three] = (search(one - 1, two, three) * one + search(one + 1, two - 1, three) * two + search(one, two + 1, three - 1) * three + n) / (one + two + three);
    return dp[one][two][three];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        if (temp == 1) a++;
        else if (temp == 2) b++;
        else if (temp == 3) c++;
    }

    printf("%.10f\n", search(a, b, c));

    return 0;
}