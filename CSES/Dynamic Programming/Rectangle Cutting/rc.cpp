#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int a, b;

ll dp[5001][5001];

int main()
{
    scanf("%d %d", &a, &b);

    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
            dp[i][j] = 100;//LLONG_MAX;
    }

    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (j == i)
                dp[i][j] = 0;
            else
            {
                for (int c = 1; c < i; ++c)
                    dp[i][j] = min(dp[i][j], dp[i - c][j] + 1);
                for (int c = 1; c < j; ++c)
                    dp[i][j] = min(dp[i][j], dp[i][j - c] + 1);
                LOG("%d %d: %lld\n", i, j, dp[i][j]);
            }

#if DEBUG
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
            LOG("%lld ", dp[i][j]);
        LOG("\n");
    }
    LOG("\n");
#endif

        }
    }

#if DEBUG
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
            LOG("%lld ", dp[i][j]);
        LOG("\n");
    }
#endif

    printf("%lld\n", dp[a][b]);
}
