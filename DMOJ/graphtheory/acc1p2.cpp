#include <queue>
#include <unordered_map>
#include <iostream>
#include <cstring>
using namespace std;
int dist[100010];
int vis[100010];
int past[100010];
int r[100010];
int head[100010];
int to[400010];
int nxt[400010];
// unordered_map<int, vector<int>> graph;
queue<int> dq;
int n, m, q;
int readInt()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
int find(int a)
{
    if (past[a] == a)
    {
        return a;
    }
    return past[a] = find(past[a]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (r[b] > r[a])
        {
            swap(a, b);
        }
        past[b] = a;
        if (r[b] == r[a])
        {
            r[a]++;
        }
    }
}

int bfs(int start, int end, int id)
{
    if (find(start) != find(end)) return -1;
    if (start == end) return 0;
    // int to_end[100010];
    // int from_end[100010];
    // int vis_to[100010] = {};
    // int vis_from[100010] = {};
    // memset(to_end, -1, (n + 1) * sizeof(to_end[0]));
    // memset(from_end, -1, (n + 1) * sizeof(from_end[0]));
    // for (int i = 0; i <= n; i++)
    // {
    //     to_end[i] = -1;
    //     from_end[i] = -1;
    // }

    dist[start] = 0;
    dist[end] = 0;
    vis[start] = id;
    vis[end] = id + 1;
    // vis_to[start] = id;
    // vis_from[end] = id + 1;
    dq = {};
    dq.push(start);
    dq.push(end);
    while (!dq.empty())
    {
        int cur_node = dq.front();
        dq.pop();
        // printf("at node %d\n", cur_node);
        for (int i = head[cur_node]; i != -1; i = nxt[i])
        {
            int e = to[i];
            // printf("looking at edge %d %d\n", e, i);
            if (vis[cur_node] == id && vis[e] == id + 1) {
                return dist[cur_node] + dist[e] + 1;
            }
            if (vis[cur_node] == id + 1 &&  vis[e] == id) {
                return dist[cur_node] + dist[e] + 1;
            }
            if (vis[cur_node] == id && vis[e] != id)
            {
                vis[e] = id;
                dist[e] = dist[cur_node] + 1;
                dq.push(e);
            }
            else if (vis[cur_node] == id + 1 && vis[e] != id + 1)
            {
                vis[e] = id + 1;
                dist[e] = dist[cur_node] + 1;
                dq.push(e);
            }
        }
    }
    return -100;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    n = readInt();
    m = readInt();
    q = readInt();
    // cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        past[i] = i;
        r[i] = 1;
        head[i] = -1;
    }
    for (int i = 0, a, b; i < m; i++)
    {
        // cin >> a >> b;
        a = readInt();
        b = readInt();
        join(a, b);
        to[i] = b;
        nxt[i] = head[a];
        head[a] = i;
        to[i + m] = a;
        nxt[i + m] = head[b];
        head[b] = i + m;
        // graph[a].push_back(b);
        // graph[b].push_back(a);
    }
    for (int i = 0, a, b; i < q; i++)
    {
        // cin >> a >> b;
        a = readInt();
        b = readInt();
        printf("%d\n", bfs(a, b, i * 2 + 1));
    }
    return 0;
}
// 10 10 1
// 10 9
// 9 8
// 8 7
// 7 6
// 6 5
// 5 4
// 4 3
// 3 2
// 2 1
// 3 8
// 10 1

// 7 7 21
// 1 2
// 1 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 2
// 1 2
// 1 3
// 1 4
// 1 5
// 1 6
// 1 7
// 2 3
// 2 4
// 2 5
// 2 6
// 2 7
// 3 4
// 3 5
// 3 6
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 5 7
// 6 7

// 5 4 3
// 1 2
// 1 4
// 2 5
// 5 4
// 2 4
// 1 3
// 5 3