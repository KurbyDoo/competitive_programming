#include <bits/stdc++.h>
using namespace std;
int n, m, s;
string t;
int attack[110], defence[110], ciel[110];
int n_attack = 0, n_defence = 0;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        if (t == "ATK") {
            attack[n_attack++] = s;
        } else {
            defence[n_defence++] = s;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> ciel[i];
    }

    sort(attack, attack + n_attack);
    sort(defence, defence + n_defence);
    sort(ciel, ciel + m);
    int max_all_cards = 0, i = 0, idx = 0;
    vector<int> unused;
    while (idx < m) {
        if (i < n_defence && ciel[idx] > defence[i]) {
            i++;
        } else {
            unused.push_back(ciel[idx]);
        }
        idx++;
    }

    if (i != n_defence || n_attack > unused.size()) {
        max_all_cards = -1;
    } else {
        sort(unused.begin(), unused.end());
        int l = n_attack - 1, r = unused.size() - 1;
        bool works = true;
        while (l >= 0) {
            if (unused[r] < attack[l]) {
                max_all_cards = -1;
                works = false;
                break;
            }
            max_all_cards += unused[r] - attack[l];
            l--; r--;
        }
        while (works && r >= 0) {
            max_all_cards += unused[r];
            r--;
        }
    }
    int max_no_def = 0;
    int l = 0, r = m - 1;
    while (r >= 0 && l < n_attack) {
        if (ciel[r] < attack[l]) break;
        max_no_def += ciel[r] - attack[l];
        r -= 1; l += 1;
    }

    printf("%d\n", max(max_no_def, max_all_cards));
    return 0;
}