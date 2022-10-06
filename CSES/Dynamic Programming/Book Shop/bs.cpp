#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;
int n, x;
int h[1000]; // prices
int s[1000]; // pages
ll dp[(int)1e5 + 1];

int main()
{
    scanf("%d %d", &n, &x);
    LOG("%d %d\n", n, x);
    for (int i = 0; i < n; ++i)
        scanf("%d", &h[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &s[i]);
#if DEBUG
    for (int i = 0; i < n; ++i)
        LOG("%d ", h[i]);
    LOG("\n");
    for (int i = 0; i < n; ++i)
        LOG("%d ", s[i]);
    LOG("\n");
#endif

    for (int i = 0; i < n; ++i)
    {
        for (int j = x; j >= h[i]; --j)
            dp[j] = max(dp[j - h[i]] + s[i], dp[j]);
    }
#if DEBUG
    for (int i = 0; i <= x; ++i)
        LOG("%d: %lld\n", i, dp[i]);
#endif
    printf("%lld\n", dp[x]);
}
