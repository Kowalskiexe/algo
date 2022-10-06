#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ul;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int t;

vector<int> inline bfs(const vector<vector<int>> adj, int s)
{
    vector<int> out;
    out.reserve(adj.size());

    queue<int> q;
    q.push(s);

    vector<bool> visited(adj.size());
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        out.push_back(v);
        LOG("\tout: %d size: %ld\n", v, q.size());
        for (int n : adj[v])
        {
            if (!visited[n])
            {
                q.push(n);
                visited[n] = true;
            }
        }
    }
    return out;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        LOG("T: %d\n", t);
        int n;
        scanf("%d", &n);

        vector<vector<int>> adj;
        adj.resize(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int from, to;
            scanf("%d %d", &from, &to);
            adj[from].push_back(to);
        }

#if DEBUG
        LOG("tree:\n");
        for (ul i = 0; i < adj.size(); ++i)
        {
            LOG("%ld: ", i);
            for (int col : adj[i])
                LOG("%d ", col);
            LOG("\n");
        }
#endif

        vector<int> b = bfs(adj, 1);
#if DEBUG
        for (int i : b)
            LOG("%d ", i);
        LOG("\n");
#endif
        int maxe = 3;
        for (auto row : adj)
            if (row.size() + 1 > maxe)
                maxe = row.size() + 1;

        vector<int> result(b.size());
        for (ul i = 0; i < b.size(); ++i)
        {
            result[b[i] - 1] = i % maxe + 1;
        }

        printf("%d\n", min(n, maxe));
        for (int i : result)
            printf("%d ", i);
        printf("\n");
    }
}
