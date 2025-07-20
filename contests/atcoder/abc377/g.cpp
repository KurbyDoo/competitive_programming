#include <bits/stdc++.h>
using namespace std;
int n;
string si;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    int depth = 0;
};

class Trie
{
private:
    TrieNode *root;
    vector<TrieNode *> euler;
    vector<int> depths;
    unordered_map<TrieNode *, int> firstOccurrence;
    vector<vector<int>> RMQ;
    vector<int> log;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode *current = root;
        int count = 0;
        for (char ch : word) {
            if (!current->children.count(ch))
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
    }

    TrieNode *getRoot()
    {
        return root;
    }
};

int main()
{
    Trie trie;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> si;
        trie.insert(si);
    }
    trie.insert("hello");
    trie.insert("world");
    trie.insert("help");

    return 0;
}
