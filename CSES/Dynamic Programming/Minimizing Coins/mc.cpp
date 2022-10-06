#include <stdio.h>
#include <climits>

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, x;
int c[(int)1e6];
int dp[(int)1e6 + 1];

int inline min(int a, int b)
{
    return (a < b)? a : b;
}

int main()
{
    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &c[i]);

    dp[0] = 0;
    for (int i = 1; i <= x; ++i)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; ++j)
            if (c[j] <= i && dp[i - c[j]] != INT_MAX)
                dp[i] = min(dp[i - c[j]] + 1, dp[i]);
    }

#if DEBUG
    for (int i = 0; i <= x; ++i)
        LOG("%d: %d\n", i, dp[i]);
#endif

    if (dp[x] == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", dp[x]);
}
