// KurbyDoo
// Feb 10th, 2024
// Problem Name
// Problem Code
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int va, vb, m;
pii last[1010][1010];
string op[1010][1010];
bool visited[1010][1010];
int dist[1010][1010];
queue<pii> q;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> va >> vb >> m;
    for (int i = 0; i <= max(va, m); i++)
    {
        for (int j = 0; j <= max(vb, m); j++)
        {
            dist[i][j] = 999999999;
        }
    }
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 0;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        // printf("at %d %d\n", a, b);
        if (!visited[va][b])
        {
            q.push({va, b});
            last[va][b] = {a, b};
            op[va][b] = "fill A";
            visited[va][b] = true;
            dist[va][b] = dist[a][b] + 1;
        }
        if (!visited[a][vb])
        {
            q.push({a, vb});
            last[a][vb] = {a, b};
            op[a][vb] = "fill B";
            visited[a][vb] = true;
            dist[a][vb] = dist[a][b] + 1;
        }

        if (a + b > vb && !visited[a + b - vb][vb])
        {
            q.push({a + b - vb, vb});
            last[a + b - vb][vb] = {a, b};
            op[a + b - vb][vb] = "pour A B";
            visited[a + b - vb][vb] = true;
            dist[a + b - vb][vb] = dist[a][b] + 1;
        }
        else if (a + b < vb && !visited[0][a + b])
        {
            q.push({0, a + b});
            last[0][a + b] = {a, b};
            op[0][a + b] = "pour A B";
            visited[0][a + b] = true;
            dist[0][a + b] = dist[a][b] + 1;
        }

        if (a + b > va && !visited[va][a + b - va])
        {
            q.push({va, a + b - va});
            last[va][a + b - va] = {a, b};
            op[va][a + b - va] = "pour B A";
            visited[va][a + b - va] = true;
            dist[va][a + b - va] = dist[a][b] + 1;
        }
        else if (a + b < va && !visited[a + b][0])
        {
            q.push({a + b, 0});
            last[a + b][0] = {a, b};
            op[a + b][0] = "pour B A";
            visited[a + b][0] = true;
            dist[a + b][0] = dist[a][b] + 1;
        }

        if (!visited[0][b])
        {
            q.push({0, b});
            last[0][b] = {a, b};
            op[0][b] = "chug A";
            visited[0][b] = true;
            dist[0][b] = dist[a][b] + 1;
        }
        if (!visited[a][0])
        {
            q.push({a, 0});
            last[a][0] = {a, b};
            op[a][0] = "chug B";
            visited[a][0] = true;
            dist[a][0] = dist[a][b] + 1;
        }
    }

    int min_dist = 9999999;
    pii best = {0, 0};

    for (int i = 0; i <= va; i++)
    {
        if (dist[i][m] < min_dist)
        {
            min_dist = dist[i][m];
            best = {i, m};
        }
        // printf("checking (%d %d) %d\n", i, m, min_dist);
    }

    for (int i = 0; i <= vb; i++)
    {
        if (dist[m][i] < min_dist)
        {
            min_dist = dist[m][i];
            best = {m, i};
        }
    }

    if (min_dist == 9999999) {
        printf("Not possible\n");
        return 0;
    }
    // printf("%d (%d %d)\n", min_dist, best.first, best.second);
    vector<string> ops;
    while (best.first != 0 || best.second != 0)
    {
        ops.push_back(op[best.first][best.second]);
        // printf("%s\n", op[best.first][best.second].c_str());
        best = last[best.first][best.second];
        // printf("back %d %d\n", best.first, best.second);
    }

    while (!ops.empty()) {
        printf("%s\n", ops.back().c_str());
        ops.pop_back();
    }

    return 0;
}
