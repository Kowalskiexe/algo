#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

vector<vector<int>> adj;

vector<bool> visited;
vector<int> parents;
bool inline dfs(int a)
{
    visited[a] = true;
    for (int u : adj[a])
    {
        if (visited[u])
        {
            // trace back
            if (a != 1)
            {
                LOG("trace back a: %d u: %d\n", a, u);
                int i = a;
                int l = 2;
                vector<int> tb;
                do
                {
                    LOG("%d, ", i);
                    tb.push_back(i);
                    i = parents[i];
                    l++;
                }
                while (i != u);
                LOG("%d, %d    |%d", u, a, l);
                tb.push_back(u);
                tb.push_back(a);
                if (l > 3)
                {
                    LOG(" win\n");
                    printf("%ld\n", tb.size());
                    for (int x : tb)
                        printf("%d ", x);
                    printf("\n");
                    return true;
                }
                LOG("\n");
            }
        }
        else
        {
            parents[u] = a;
            visited[u] = true;
            bool suc = dfs(u);
            if (suc)
                return true;
        }
    }
    return false;
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
    for (int i = 0; i <= n; ++i)
    {
        LOG("%d: ", i);
        for (int j : adj[i])
            LOG("%d, ", j);
        LOG("\n");
    }
#endif
    visited.resize(n + 1);
    parents.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            bool suc = dfs(i);
            if (suc) 
                return 0;
        }
    }
    printf("IMPOSSIBLE\n");
}
