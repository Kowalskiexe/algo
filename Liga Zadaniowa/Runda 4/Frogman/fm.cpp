#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int o, n, t;
const int owc = 80;
const int nwc = 135;
int dp[owc][nwc];
int main()
{
    scanf("%d %d\n%d", &o, &n, &t);
    LOG("%d %d\n%d\n", o, n, t);

    for (int i = 0; i < owc; ++i)
    {
        for (int j = 0; j < nwc; ++j)
            dp[i][j] = INT_MAX;
    }
    dp[0][0] = 0;
    
    for (int i = 0; i < t; ++i)
    {
        int no, nn, nm;
        scanf("%d %d %d", &no, &nn, &nm);
        for (int xo = owc - 1; xo >= no; --xo)
        {
            for (int xn = nwc - 1; xn >= nn; --xn)
            {
                int xbo = xo - no;
                int xbn = xn - nn;
                if (dp[xbo][xbn] != INT_MAX)
                    dp[xo][xn] = min(dp[xo][xn], dp[xbo][xbn] + nm);
            }
        }
    }

#if DEBUG
    for (int i = 0; i < owc; ++i)
    {
        for (int j = 0; j < nwc; ++j)
        {
            if (dp[i][j] != INT_MAX)
                LOG("%d %d: %d\n", i, j, dp[i][j]);
        }
    }
#endif

    int result = INT_MAX;
    for (int i = o; i < owc; ++i)
    {
        for (int j = n; j < nwc; ++j)
            result = min(dp[i][j], result);
    }
    printf("%d\n", result);
}
