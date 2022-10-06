#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

vector<vector<pair<int, ll>>> adj;

vector<ll> dist;
void inline dijkstra()
{
    priority_queue<pair<ll, int>> q;
    dist.resize(n + 1);
    for (int i = 1; i <= n; ++i)
            dist[i] = LLONG_MAX;
    dist[1] = 0;
    vector<bool> processed(n + 1);
    q.push({0, 1});
    while (!q.empty())
    {
        ll a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            ll b = u.first, w = u.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
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
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        adj[a].emplace_back(b, w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
        printf("%lld ", dist[i]);
    printf("\n");
}
