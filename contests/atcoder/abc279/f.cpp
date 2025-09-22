#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll n, q, tt, xi, yi;
vector<int> balls[300010];
unordered_map<int, int> loc;
unordered_map<int, int> label_pos;
unordered_map<int, int> pos_label;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        balls[i].push_back(i);
        label_pos[i] = i;
        pos_label[i] = i;
        loc[i] = i;
    };

    for (int i = 1; i <= q; i++) {
        cin >> tt;
        if (tt == 1) {
            cin >> xi >> yi;
            if (balls[label_pos[yi]].size() > balls[label_pos[xi]].size()) {
                swap(pos_label[label_pos[yi]], pos_label[label_pos[xi]]);
                swap(label_pos[yi], label_pos[xi]);
            }

            for (int ball : balls[label_pos[yi]]) {
                balls[label_pos[xi]].push_back(ball);
                loc[ball] = label_pos[xi];
            }

            balls[label_pos[yi]].clear();
        } else if (tt == 2) {
            cin >> xi;
            n++;
            balls[label_pos[xi]].push_back(n);
            loc[n] = label_pos[xi];
        } else {
            cin >> xi;
            printf("%d\n", pos_label[loc[xi]]);
        }
    }
    return 0;
}