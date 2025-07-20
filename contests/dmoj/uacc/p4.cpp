#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef double ;
typedef pair<int, int> pii;
int n, m;
double inital_pollution[100010];
double pollution[100010];
double flow_strength[100010];
double temp1[100010];
int parents[100010];
queue<int> q;
unordered_map<int, vector<pair<int, double>>> graph;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c * 0.01});
        parents[b]++;
    }

    for (int i = 1, a; i <= n; i++)
    {
        cin >> inital_pollution[i];
        if (parents[i] == 0) {
            q.push(i);
            flow_strength[i] = 1.0;
            pollution[i] = inital_pollution[i];
        }
    }

    while (!q.empty())
    {
        int cur_node = q.front();
        // printf("pushing %d with pollution of %f\n", cur_node, pollution[cur_node]);
        q.pop();

        for (auto [e, p] : graph[cur_node])
        {
            // printf("adding %f to %d\n", pollution[cur_node] * p, e);
            pollution[e] += pollution[cur_node] * p * flow_strength[cur_node];
            flow_strength[e] += flow_strength[cur_node] * p;
            parents[e]--;
            if (parents[e] == 0) {
                q.push(e);
                pollution[e] = pollution[e] / flow_strength[e] + inital_pollution[e];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%.14f\n", pollution[i]);
    }

    // printf("%f\n", 100.0 * 0.27 / 0.68 + 140.0 * 0.41 / 0.68 + 36.0);
    return 0;
}