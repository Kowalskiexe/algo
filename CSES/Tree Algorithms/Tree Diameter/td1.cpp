#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> adj;

vector<int> dist;
void dfs(int s, int e, int d)
{
    dist[s] = d;
    for (int u : adj[s])
    {
        if (u == e) continue;
        dfs(u, s, d + 1);
    }
}
    

int main()
{
    scanf("%d", &n);

    if (n == 1)
    {
        printf("0\n");
        return 0;
    }

    adj.resize(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist.resize(n + 1);
    dfs(1, 0, 1);
    int b = -1;
    int bdist = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] > bdist)
        {
            bdist = dist[i];
            b = i;
        }
    }

    dist.resize(n + 1);
    dfs(b, 0, 1);
    int result = -1;
    for (int i = 1; i <= n; ++i)
        result = max(result, dist[i]);
    
    printf("%d\n", result - 1);
}

