#include <bits/stdc++.h>

typedef long long ll;

const ll M = 1e9 + 7;

int n;
ll dp[(int)1e6 + 1];

int main()
{
    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    for (int i = 7; i <= n; ++i)
    {
        for (int j = 1; j <= 6; ++j)
            dp[i] = (dp[i] + dp[i - j]) % M;
    }

    printf("%lld\n", dp[n]);
}

