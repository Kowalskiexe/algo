#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<vector<int>> adj;
vector<int> v;

vector<bool> vis;
vector<int> parent;
void inline bfs(int x)
{
    queue<int> q;
    vis[x] = true;
    q.push(x);
    
    while (!q.empty())
    {
        int s = q.front(); q.pop();
        for (int u : adj[s])
        {
            if (vis[u]) continue;
            vis[u] = true;
            parent[u] = s;
            q.push(u);
        }
    }
}

int main()
{
    scanf("%d", &n);
    LOG("n: %d\n", n);

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> leaves;
    leaves.reserve(n);
    for (int i = 2; i <= n; ++i)
        if (adj[i].size() == 1)
            leaves.push_back(i);
#if DEBUG
    LOG("leaves: ");
    for (int l : leaves)
        LOG("%d ", l);
    LOG("\n");
#endif
    
    parent.resize(n + 1);
    vis.resize(n + 1);
    bfs(1);
#if DEBUG
    LOG("bfs:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d: %d\n", i, parent[i]);
#endif
    v.resize(n + 1);
    vector<int> out(n + 1);
    for (int i = 0; i < leaves.size(); ++i)
    {
        int curr = leaves[i];
        int height = 1;
        while (curr != 1)
        {
            LOG("is %d, s: %ld\n", curr, adj[curr].size());
            if (adj[curr].size() <= 2)
            {
                LOG("just branch\n");
                out[curr] = height;
            }
            else
            {
                LOG("connection\n");
                int mv0 = -1, mv1 = -1;
                for (int i = 0; i < adj[curr].size(); ++i)
                {
                    if (adj[curr][i] == parent[curr])
                        continue;
                    if (out[adj[curr][i]] >= mv1)
                    {
                        mv0 = mv1;
                        mv1 = out[adj[curr][i]];
                    }
                }
                out[curr] = mv0 + mv1 + 1;
            }
            LOG("-> %d\n", parent[curr]);
            curr = parent[curr];
            height++;
        }
    }
#if DEBUG
    LOG("out:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d: %d\n", i, out[i]);
#endif
    LOG("real output:\n");
    for (int i = 2; i <= n; ++i)
        printf("%d ", out[i]);
    LOG("\n");
}
