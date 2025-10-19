#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

bool query(string s) {
    cout << s << endl;
    cin >> s;
    return s == "1";
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    if (query("? 2 2")) {
        if (query("? 2 1")) {
            cout << (query("? 1 1") ? "! 1 1" : "! 2 1") << endl;
        } else {
            cout << (query("? 1 2") ? "! 1 2" : "! 2 2") << endl;
        }
    } else {
        if (query("? 4 2")) {
            cout << (query("? 4 1") ? "! 4 1" : "! 4 2") << endl;
        } else {
            if (query("? 2 4")) {
                cout << (query("? 1 4") ? "! 1 4" : "! 2 4") << endl;
            } else {
                count << (query("? 3 3") ? "! 3 3" : "! 4 4")
                cout << "! 4 4" << endl;
            }
        }
    }

    return 0;
}