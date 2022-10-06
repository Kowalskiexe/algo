#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, k;

int total;
set<pair<int, int>> blocked;
vector<vector<int>> adj;

int f(int x, int y) {
    return x + (y - 1) * n; }

vector<bool> vis;
void dfs(int x, int& v) {
    if (vis[x]) return;
    vis[x] = true;
    v++;
    for (int u : adj[x])
        if (blocked.count({x, u}) == 0)
            dfs(u, v);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    total = n * m;
    adj.resize(total + 1);

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            // up
            if (y > 1)
                adj[f(x, y)].push_back(f(x, y - 1));
            // down
            if (y < m)
                adj[f(x, y)].push_back(f(x, y + 1));
            // left
            if (x > 1)
                adj[f(x, y)].push_back(f(x - 1, y));
            // right
            if (x < n)
                adj[f(x, y)].push_back(f(x + 1, y));
        }
    }

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int a = f(x1, y1);
        int b = f(x2, y2);
        blocked.insert({a, b});
        blocked.insert({b, a});
        vis.clear();
        vis.resize(total + 1);
        int visited = 0;
        dfs(1, visited);
        if (visited == total)
            printf("TAK\n");
        else {
            printf("NIE\n");
            blocked.erase({a, b});
            blocked.erase({b, a});
        }
    }
}

