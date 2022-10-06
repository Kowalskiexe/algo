#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

deque<int> inline bfs()
{
    deque<int> out;
    queue<int> q;
    vector<bool> visited(n + 1);
    vector<int> p(n + 1);
    p[1] = 1;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int a = q.front(); q.pop();
        if (a == n)
        {
            while (a != 1)
            {
                out.push_front(a);
                a = p[a];
            }
            out.push_front(1);

            return out;
        }
        visited[a] = true;
        for (int u : adj[a])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
                p[u] = a;
            }
        }
    }
    return out;
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
    deque<int> res = bfs();
    if (res.empty())
    {
        printf("IMPOSSIBLE\n");
    }
    else
    {
        printf("%ld\n", res.size());
        for (int e : res)
            printf("%d ", e);
        printf("\n");
    }
}
