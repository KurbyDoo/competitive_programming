#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
ll n, a, b, c;
ll graph[1010][1010];
ll dist[2][1010];
const ll maxV = 10000000000000;
bool visited[1010];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> a >> b >> c;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            cin >> graph[x][y];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dist[0][i] = maxV;
        dist[1][i] = maxV;
    }
    dist[0][1] = 0;
    dist[1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int curV = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (curV == -1 || dist[0][j] < dist[0][curV]))
                curV = j;
        }

        // printf("l1 at %d d = %lld\n", curV, dist[0][curV]);
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%lld ", dist[0][i]);
        // }
        // printf("\n");
        if (dist[0][curV] == maxV)
            break;

        visited[curV] = true;
        for (int j = 1; j <= n; j++)
        {
            if (curV == j)
                continue;
            if (dist[0][curV] + graph[curV][j] * a < dist[0][j])
            {
                dist[0][j] = dist[0][curV] + graph[curV][j] * a;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        int curV = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (curV == -1 || dist[1][j] < dist[1][curV]))
                curV = j;
        }

        if (dist[1][curV] == maxV)
            break;

        visited[curV] = true;
        for (int j = 1; j <= n; j++)
        {
            if (curV == j)
                continue;

            if (dist[0][curV] + graph[curV][j] * b + c < dist[1][j])
            {
                dist[1][j] = dist[0][curV] + graph[curV][j] * b + c;
            }
            if (dist[1][curV] + graph[curV][j] * b + c < dist[1][j])
            {
                dist[1][j] = dist[1][curV] + graph[curV][j] * b + c;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%lld ", dist[0][i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%lld ", dist[1][i]);
    // }
    // printf("\n");
    printf("%lld\n", min(dist[0][n], dist[1][n]));
    return 0;
}