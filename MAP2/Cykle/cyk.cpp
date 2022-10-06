#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<vector<int>> adj;
int n, m, result;

vector<bool> visited;
vector<int> parent;
void dfs(int x)
{
    if (visited[x]) return;
    visited[x] = true;
    for (int u : adj[x])
    {
        if (!visited[u])
        {
            parent[u] = x;
            dfs(u);
        }
        else
        {
            if (parent[x] != u)
            {
                LOG("cycle, x: %d u: %d\n", x, u);
                result++;
            }
        }
    }
}


int main()
{
    scanf("%d %d", &n, &m);

    adj.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
#if DEBUG
    for (int i = 1; i <= n; ++i)
    {
        LOG("%d: ", i);
        for (int u : adj[i])
            LOG("%d, ", u);
        LOG("\n");
    }
#endif
    visited.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        dfs(i);
    printf("%d\n", result / 2);
}
    
