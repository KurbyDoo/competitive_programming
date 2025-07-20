#include <bits/stdc++.h>
using namespace std;
struct Node {
    int next[2];
    bool leaf;
    int idx;
    Node() { 
        leaf = false;
        fill(begin(next), end(next), -1);
    }
};

vector<Node> trie(1);

void update(int val, int idx) {
    int x = 0;
    for (int i = 31; i >= 0; i--) {
        int c = (val >> i) & 1;
        if (trie[x].next[c] == -1) {
            // printf("creating from %d (%d) of %d\n", i, c, val);
            trie[x].next[c] = trie.size();
            trie.emplace_back();
        }
        x = trie[x].next[c];
    }
    if (trie[x].leaf) return;
    trie[x].leaf = true;
    trie[x].idx = idx;
}

int query(int val) {
    int x = 0;
    int temp = 0;
    for (int i = 31; i >= 0; i--) {
        int c = (val >> i) & 1;
        if (trie[x].next[c] == -1) {
            temp ^= (c ^ 1) << i; 
        } else {
            temp ^= c << i;
        }
        // printf("at = %d\n", temp);
        x = trie[x].next[c] == -1 ? trie[x].next[c ^ 1] : trie[x].next[c];
    }
    // printf("node is %d\n", trie[x].leaf);
    return trie[x].idx;
}

int n, q, a;
int main() { 
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a;
        update(a, i);
    };

    int change = 0;
    for (int i = 0; i < q; i++) {
        cin >> a;
        change ^= a;
        printf("%d\n", query(change));
    }
}