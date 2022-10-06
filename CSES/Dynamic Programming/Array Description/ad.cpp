#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll M = 1e9 + 7;

int n, m;
ll dp[(int)1e5 + 1][101];

int main()
{
    scanf("%d %d", &n, &m);

    int v0;
    scanf("%d", &v0);

    if (v0 == 0)
    {
        for (int i = 1; i <= m; ++i)
            dp[0][i] = 1;
    }
    else
        dp[0][v0] = 1;

    for (int i = 1; i < n; ++i)
    {
        int v;
        scanf("%d", &v);
        if (v == 0)
        {
            for (int j = 1; j <= m; ++j)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % M;
        }
        else
            dp[i][v] = (dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1]) % M;
    }
    ll out = 0;
    for (int i = 1; i <= m; ++i)
        out = (out + dp[n - 1][i]) % M;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            LOG("%lld ", dp[i][j]);
        LOG("\n");
    }
    printf("%lld\n", out);
}
