#include <iostream>
#include <vector>
#include <algorithm>

const long long M = 1e9 + 7;

int n, x;
std::vector<int> c;

std::vector<std::vector<long long>> dp;

int main()
{
    scanf("%d %d", &n, &x);
    
    dp.resize(x + 1);
    c.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &c[i]);
    
    std::sort(c.begin(), c.end());

    for (auto i : dp)
        i.resize(x);

    for (int i = 0; i < n; ++i)
        dp[0][i] = 1;

    for (int i = 1; i <= x; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j > 0)
                dp[i][j] = dp[i][j - 1];
            if (i - c[j] >= 0)
                dp[i][j] = (dp[i][j] + dp[i - c[j]][j]) % M;
        }
    }
    printf("%lld\n", dp[x][n - 1]);
}


