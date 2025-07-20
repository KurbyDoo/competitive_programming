#include<iostream>
using namespace std;
int n, q;
int past[6000010];
short depth[6000010];
int lca(int n1, int n2) {
    if (depth[n1] > depth[n2])
        swap(n1, n2);
    for (int i = depth[n2]; i > depth[n1]; i--)
    {
        n2 = past[n2];
    }
    while (n1 != n2)
    {
        n1 = past[n1];
        n2 = past[n2];
    }
    return n1;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    depth[1] = 0;
    for (int i = 2, a; i <= n; i++) {
        cin >> a;
        past[i] = a;
        depth[i] = depth[a] + 1;
    }

    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        printf("%d\n", lca(a, b));
    }
}