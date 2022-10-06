#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int t[(int)5e5];
int dp[(int)5e5];

int main()
{
    scanf("%d", &n);

    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        t[i] = 9 - in;
        sum += in;
    }
    dp[0] = t[0];
    for (int i = 1; i < n; ++i)
        dp[i] = max(t[i] + dp[i - 2], dp[i - 1]);
    ll res = sum + dp[n - 1];
    printf("%lld\n", res);
}
