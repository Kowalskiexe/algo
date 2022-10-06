#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

vector<vector<int>> adj;
vector<int> teams;

bool inline dfs(int p, int team)
{
    teams[p] = team;
    bool suc = true;
    for (int u : adj[p])
    {
        if (teams[u] == team)
        {
            LOG("nope\n");
            return false;
        }
        else if (teams[u] == 0)
            suc = dfs(u, team % 2 + 1) && suc;
    }
    return suc;
}

int main()
{
    scanf("%d %d", &n, &m);
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    teams.resize(n + 1);
    bool suc = false;
    for (int i = 1; i <= n; ++i)
    {
        if (teams[i] == 0)
            suc = dfs(i, 1);
        if (!suc) break;
        
    }
#if DEBUG
    for (int i = 1; i <= n; ++i)
        LOG("%d\n", teams[i]);
#endif
    if (suc)
    {
        for (int i = 1; i <= n; ++i)
            printf("%d ", teams[i]);
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");
}

