#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
vector<pll> adj[500010];
ll min_d[500010];
ll sz[500010];
vector<pll> parents[500010];
bool rem[500010];

int get_sz(int node, int past) {
    sz[node] = 1;
    for (auto [a, b]: adj[node]) {
        if (a == past || rem[a]) continue;
        sz[node] += get_sz(a, node);
    }
    return sz[node];
}

int get_ctr(int node, int past, int tsz) {
    for (auto [a, b]: adj[node]) {
        if (a == past || rem[a]) continue;
        if (sz[a] * 2 > tsz) return get_ctr(a, node, tsz);
    }
    return node;
}

void get_dist(int node, int past, int centroid, ll cur_dist) {
    for (auto [a, b]: adj[node]) {
        if (a == past || rem[a]) continue;
        get_dist(a, node, centroid, cur_dist + b);
    }
    parents[node].push_back({centroid, cur_dist});
}

void build(int node) {
    int ctr = get_ctr(node, -1, get_sz(node, -1));

    for (auto [a, b]: adj[ctr]) {
        if (rem[a]) continue;
        get_dist(a, ctr, ctr, b);
    }

    rem[ctr] = true;
    for (auto [a, b]: adj[ctr]) {
        if (rem[a]) continue;
        build(a);
    }
}

void Init(int N, int A[], int B[], int D[]) {
    for (int i = 0; i < N - 1; i++) {
        min_d[i] = INF;
        adj[A[i]].push_back({B[i], D[i]});
        adj[B[i]].push_back({A[i], D[i]});
    }
    min_d[N - 1] = INF;

    build(1);
}

void paint(int node) {
    for (auto [a, b]: parents[node]) {
        min_d[a] = min(min_d[a], b);
    }
    min_d[node] = 0;
}

ll find(int node) {
    ll ans = min_d[node];
    for (auto [a, b]: parents[node]) {
        ans = min(ans, min_d[a] + b);
    }
    return ans;
}

void res(int node) {
    for (auto [a, b]: parents[node]) {
        min_d[a] = INF;
    }
    min_d[node] = INF;
}

long long Query(int S, int X[], int T, int Y[]) {
    for (int i = 0; i < S; i++) {
        paint(X[i]);
    }

    ll ans = INF;
    for (int i = 0; i < T; i++) {
        ans = min(ans, find(Y[i]));
    }

    for (int i = 0; i < S; i++) {
        res(X[i]);
    }
    return ans;
}

// int main() {
//     int arr1[] = {0, 1, 2, 2, 4, 1};
//     int arr2[] = {1, 2, 3, 4, 5, 6};
//     int arr3[] = {4, 4, 5, 6, 5, 3};
//     Init(7, arr1, arr2, arr3);
//     // Init(7, {0, 1, 2, 2, 4, 1}, {1, 2, 3, 4, 5, 6}, {4, 4, 5, 6, 5, 3});
//     int arrA[] = {0, 6};
//     int arrB[] = {3, 4};
//     printf("%lld\n", Query(2, arrA, 2, arrB)); //returns 12.
//     int arrC[] = {0, 1, 3};
//     int arrD[] = {4, 6};
//     printf("%lld\n", Query(3, arrC, 2, arrD)); //returns 3.
//     int arrE[] = {2};
//     int arrF[] = {5};
//     printf("%lld\n", Query(1, arrE, 1, arrF)); //returns 11.
//     return 0;
// }