#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, u, v;
int have[250];
int want[250];
int capacity[250][250];
int past[250];
int sn, en, tot1, tot2;
const int MAX = 10000000;

int bfs() {
    fill(begin(past), begin(past) + en + 10, -1);
    past[sn] = -2;
    queue<pii> q;
    q.push({sn, MAX});
    while (!q.empty()) {
        pii nn = q.front();
        // printf("at %d\n", nn.first);
        q.pop();
        for (int i = 0; i <= en; i++) {
            if (past[i] == -1 && capacity[nn.first][i]) {
                int flow = min(nn.second, capacity[nn.first][i]);
                past[i] = nn.first;
                if (i == en) return flow;
                q.push({i, flow});
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    sn = 0;
    en = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> have[i];
        tot1 += have[i];
        capacity[sn][i] = have[i];
        // printf("0 -> %d = %d\n", i, have[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> want[i];
        tot2 += want[i];
        capacity[i + n][en] = want[i];
        capacity[i][i + n] = MAX;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        capacity[u][v + n] = MAX;
        capacity[v][u + n] = MAX;
    }

    int total_flow = 0;
    int next_flow = 0;
    while (next_flow = bfs()) {
        total_flow += next_flow;
        // printf("found flow %d\n", next_flow);
        int cur = en;
        while (cur != sn) {
            // printf("    %d -> %d = %d\n", past[cur], cur,
            //        capacity[past[cur]][cur]);
            capacity[past[cur]][cur] -= next_flow;
            capacity[cur][past[cur]] += next_flow;
            cur = past[cur];
        }
    }

    if (tot1 == tot2 && tot1 == total_flow) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ",
                       capacity[i][j + n] > 0 ? MAX - capacity[i][j + n] : 0);
                // printf("%d ", capacity[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("NO\n");
    }
}