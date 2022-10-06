#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int n, m;

vector<bool> visited;
void inline dfs(int p)
{
    if (visited[p]) return;
    visited[p] = true;
    for (int u : adj[p])
        dfs(u);
}

int main()
{
    scanf("%d %d", &n, &m);
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        adj[to].push_back(from);
        adj[from].push_back(to);
    }
    visited.resize(n + 1);
    dfs(1);
    vector<int> r;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            r.push_back(i);
        }
    }
    printf("%ld\n", r.size());
    for (int i : r)
        printf("1 %d ", i);
    printf("\n");
}
