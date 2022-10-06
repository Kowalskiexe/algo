#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, k, q;

vector<vector<vector<int>>> v;
vector<vector<vector<ll>>> pre;

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    v.resize(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        v[i].resize(m + 1);
        for (int j = 0; j <= m; ++j)
            v[i][j].resize(k + 1);
    }

    pre.resize(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        pre[i].resize(m + 1);
        for (int j = 0; j <= m; ++j)
            pre[i][j].resize(k + 1);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int w = 1; w <= k; ++w)
                scanf("%d", &v[i][j][w]);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int w = 1; w <= k; ++w)
                pre[i][j][w] = (v[i][j][w]
                        + pre[i - 1][j][w] // orange
                        + pre[i][j - 1][w] // yellow
                        - pre[i - 1][j - 1][w] // yellow
                        + pre[i][j][w - 1] ///
                        - pre[i - 1][j][w - 1] ///
                        - pre[i][j - 1][w - 1] ///
                        + pre[i - 1][j - 1][w - 1] ///
                        );
#if DEBUG
    LOG("raw:\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int w = 1; w <= k; ++w)
                LOG("%d ", v[i][j][w]);
            LOG("\n");
        }
        LOG("\n");
    }
    LOG("pre:\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int w = 1; w <= k; ++w)
                LOG("%lld ", pre[i][j][w]);
            LOG("\n");
        }
        LOG("\n");
    }
#endif
    scanf("%d", &q);
    for (int t = 0; t < q; ++t)
    {
        int i, j, w, x, y, z;
        scanf("%d %d %d %d %d %d", &i, &x, &j, &y, &w, &z);
        ll out = (pre[i][j][w]
                - pre[i][j][z - 1] // red
                - pre[x - 1][j][w] // blue
                + pre[x - 1][j][z - 1] // blue
                - pre[i][y - 1][w] // green
                + pre[i][y - 1][z - 1] /// green
                + pre[x - 1][y - 1][w]
                - pre[x - 1][y - 1][z - 1]
                );
        printf("%lld\n", out);
    }
}
