#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> adj;

vector<int> counts;
void dfs(int s, int e)
{
    counts[s] = 1;
    for (int u : adj[s])
    {
        if (u == e) continue;
        dfs(u, s);
        counts[s] += counts[u];
    }
}

int main()
{
    scanf("%d", &n);

    counts.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        int boss;
        scanf("%d", &boss);
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i)
        printf("%d ", counts[i] - 1);
    printf("\n");
}

