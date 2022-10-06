#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const int INF = 1e9;

vector<vector<int>> adj;
vector<vector<int>> dist;
int n;

void init(int N, int S) {
    n = N;
    dist.resize(n + 1, vector<int>(n + 1, INF));
}

void build(int x, int y, int m) {
    LOG("build %d %d %d\n", x, y, m);
    dist[x][y] = m;
    dist[y][x] = m;
    int k = x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    k = y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int path(int x, int y) {
    LOG("path %d %d\n", x, y);
    return dist[x][y];
}
