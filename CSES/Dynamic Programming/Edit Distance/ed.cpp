#include <bits/stdc++.h>

typedef long long ll;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char x[5001];
char y[5001];

ll dp[5001][5001];

ll inline cost(int a, int b)
{
    return (x[a] == y[b]) ? 0 : 1;
}

ll inline min(ll a, ll b, ll c)
{
    a = (a < b) ? a : b;
    a = (a < c) ? a : c;
    return a;
}

int main()
{
    scanf("%s %s", x, y);
    int n = strlen(x);
    int m = strlen(y);
    LOG("%s %d %s %d\n", x, n, y, m);

    for (int i = 0; i <= n; ++i)
        dp[i][0] = i;

    for (int i = 0; i <= m; ++i)
        dp[0][i] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + cost(i - 1, j - 1));
    }
#if DEBUG
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
            LOG("%lld ", dp[i][j]);
        LOG("\n");
    }
#endif
    printf("%lld\n", dp[n][m]);
}
