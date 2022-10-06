#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

vector<vector<int>> adj;
vector<vector<int>> adjrev;

vector<int> out;
vector<bool> visited;
void dfs(const vector<vector<int>>& adj, int x, vector<int>& topo) {
    if (visited[x]) return;
    visited[x] = true;
    for (int u : adj[x])
        dfs(adj, u, topo);
    topo.push_back(x);
}

vector<bool> visitedrev;
vector<int> compid;
void dfsrev(int x, int id, int& size) {
    if (visitedrev[x]) return;
    visitedrev[x] = true;
    for (int u : adjrev[x])
        dfsrev(u, id, size);
    size++;
    compid[x] = id;
}

vector<bool> visited3;
vector<vector<int>> compadj;
void dfs3(int x, int prev) {
    if (prev != 0 && compid[x] != compid[prev])
        compadj[compid[prev]].push_back(compid[x]);
    if (visited3[x]) return;
    visited3[x] = true;
    for (int u : adj[x])
        dfs3(u, x);
}

int main() {
    scanf("%d %d", &n, &m);

    adj.resize(n + 1);
    adjrev.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adjrev[b].push_back(a);
    }

    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
        dfs(adj, i, out);
    for (int i : out)
        LOG("%d, ", i);
    LOG("\n");

    // 2nd phase
    visitedrev.resize(n + 1);
    int comps = 1;
    compid.resize(n + 1);
    vector<int> sizes(1);
    for (int i = n - 1; i >= 0; i--) {
        int size = 0;
        dfsrev(out[i], comps, size);
        if (size > 0) {
            comps++;
            sizes.push_back(size);
        }
    }
    comps--;
    sizes.pop_back();

    LOG("strongly connected components:\n");
    for (int i = 1; i <= n; i++)
        LOG("%d ", i);
    LOG("\n");
    for (int i = 1; i <= n; i++)
        LOG("%d ", compid[i]);
    LOG("\n");


    // 3rd phase
    visited3.resize(n + 1);
    compadj.resize(comps + 1);
    for (int i = 1; i <= n; i++)
        dfs3(i, 0);

    LOG("SCC graph:\n");
    for (int i = 1; i <= comps; i++) {
        LOG("%d: ", i);
        for (int u : compadj[i])
            LOG("%d ", u);
        LOG("\n");
    }

    // 4th phase
    vector<int> topo2;
    visited.clear();
    visited.resize(comps + 1);
    for (int i = 1; i <= comps; i++)
        dfs(compadj, i, topo2);

    LOG("SCC g. topo. sort:\n");
    for (int i : topo2)
        LOG("%d ", i);
    LOG("\n");


    // 5th phase
    vector<int> d(comps + 1);
    for (int t : topo2) {
        d[t] = sizes[t];
        for (int u : compadj[t])
            d[t] += d[u];
    }

    for (int i = 1; i <= comps; i++)
        LOG("%d: %d\n", i, d[i]);

    // result
    for (int i = 1; i <= n; i++)
        printf("%d\n", d[compid[i]] - 1);
}
    
