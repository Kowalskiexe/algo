#include <bits/stdc++.h>

typedef long long ll;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll M = 1e9 + 7;
int n;
ll dp[1001][1001];
char m[1001][1001];

int main()
{
    scanf("%d", &n);

    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x)
            scanf(" %c", &m[x][y]);
#if DEBUG
    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
            LOG("%c", m[x][y]);
        LOG("\n");
    }
#endif

    if (m[1][1] == '*')
    {
        printf("0\n");
        return 0;
    }
    dp[1][1] = 1;
    for (int y = 2; y <= n; ++y)
    {
        if (m[1][y] == '*')
            break;
        else
            dp[1][y] = 1;
    }
    for (int x = 2; x <= n; ++x)
    {
        if (m[x][1] == '*')
            break;
        else
            dp[x][1] = 1;
    }

    for (int x = 2; x <= n; ++x)
        for (int y = 2; y <= n; ++y)
            if (m[x][y] != '*')
                dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % M;

#if DEBUG
    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
            LOG("%lld ", dp[x][y]);
        LOG("\n");
    }
#endif


    printf("%lld\n", dp[n][n]);
}
