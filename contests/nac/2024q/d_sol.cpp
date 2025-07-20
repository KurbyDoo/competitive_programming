#define int long long
#define yn djakljdlkadsf
using namespace std;

int n;
int x, y;
int sz[100005];
int c[100005], ptr[100005], ans[100005], nodeans[100005];
map<int, int> freq[100005], tfreq;
vector<array<int, 2>> gph[100005];

void dfs(int id)
{
    sz[id] = 1;
    int mxid = -1, mxeid;
    for (auto [i, eid] : gph[id])
    {
        if (!sz[i])
        {
            dfs(i);
            sz[id] += sz[i];
            ans[eid] = nodeans[i];
            if (mxid == -1 || sz[i] > sz[mxid])
            {
                mxid = i;
                mxeid = eid;
            }
        }
    }
    nodeans[id] = nodeans[mxid];
    for (auto [i, eid] : gph[id])
    {
        if (i != mxid)
        {
            for (auto [key, val] : freq[ptr[i]])
            {
                nodeans[id] -= freq[ptr[mxid]][key] * (tfreq[key] - freq[ptr[mxid]][key]);
                freq[ptr[mxid]][key] += val;
                nodeans[id] += freq[ptr[mxid]][key] * (tfreq[key] - freq[ptr[mxid]][key]);
            }
        }
    }
    if (mxid != -1)
        ptr[id] = ptr[mxid];
    nodeans[id] -= freq[ptr[id]][c[id]] * (tfreq[c[id]] - freq[ptr[id]][c[id]]);
    freq[ptr[id]][c[id]]++;
    nodeans[id] += freq[ptr[id]][c[id]] * (tfreq[c[id]] - freq[ptr[id]][c[id]]);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        ptr[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        tfreq[c[i]]++;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        gph[x].push_back({y, i});
        gph[y].push_back({x, i});
    }
    dfs(1);
    for (int i = 1; i < n; i++)
        cout << ans[i] << "\n";
}

signed main()
{
    cout << fixed << setprecision(10);
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T-- > 0)
    {
        solve();
    }
}