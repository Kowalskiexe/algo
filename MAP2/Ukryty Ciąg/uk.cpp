#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, q;

vector<vector<int>> adj;
set<pair<int, int>> me;

vector<bool> visited;
vector<int> parent;
void tb_cyc(int start, int end)
{
    LOG("tc s: %d e: %d\n", start, end);
    while (start != end)
    {
        auto it = me.find({parent[start], start});
        if (it != me.end())
        {
            LOG("cycle contains m edge\n");
            return;
        }
        start = parent[start];
    }
}

void inline dfs(int x)
{
    if (visited[x]) return;
    visited[x] = true;
    LOG("dfs in: %d\n", x);
    for (int u : adj[x])
    {
        LOG("proc: %d\n", u);
        if (!visited[u])
        {
            parent[u] = x;
            LOG("p[%d] = %d\n", u, x);
            dfs(u);
        }
        else
        {
            tb_cyc(x, u);
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);

    adj.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[b].push_back(a);
        me.insert({b, a});
    }

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[b].push_back(a);
    }

    visited.resize(n + 1);
    parent.resize(n + 1);
    LOG("dfs begin\n");
    for (int i = 1; i <= n; ++i)
        dfs(i);
}

