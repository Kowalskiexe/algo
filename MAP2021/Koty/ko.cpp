#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

vector<vector<int>> adj;
vector<bool> cats;

int result = 0;
vector<bool> visited;
void inline desc(int x, int c)
{
    LOG("decs: %d\n", x);
    visited[x] = true;

    if (cats[x])
    {
        LOG("cat in %d\n", x);
        c++;
        if (c > m)
            return;
    }
    else
        c = 0;

    int desced = 0;
    for (int u : adj[x])
    {
        if (!visited[u])
        {
            visited[u] = true;
            desced++;
            desc(u, c);
        }
    }
    if (desced == 0)
    {
        LOG("result++ %d\n", x);
        result++;
        return;
    }

}

int main()
{
    scanf("%d %d", &n, &m);
    // printf("%d|%d|", n, m);
    cats.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        // printf("[%d]", in);
        cats[i] = in == 1;
    }
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        // printf("(%d|%d)", x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

#if DEBUG
    LOG("\n");
    for (int i = 1; i <= n; ++i)
    {
        LOG("%d: ", i);
        for (int u : adj[i])
            LOG("%d ", u);
        LOG("\n");
    }
    LOG("cats:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d: %d\n", i, (int)cats[i]);
#endif

    visited.resize(n + 1);
    desc(1, 0);
    printf("%d\n", result);
}
