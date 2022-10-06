#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

int n, x;
vector<int> c;
ll dp[(int)1e6 + 1];

int main()
{
    scanf("%d %d", &n, &x);

    c.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &c[i]);

    dp[0] = 1;
    for (int i = 1; i <= x; ++i)
    {
        for (int j : c)
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % M;
    }
    printf("%lld\n", dp[x]);
}
