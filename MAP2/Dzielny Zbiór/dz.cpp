#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<int> v;

int main()
{
    scanf("%d", &n);
    
    v.resize(n);
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
        mx = max(mx, v[i]);
    }

    sort(v.begin(), v.end());

#if DEBUG
    LOG("input:\n");
    for (int i = 0; i < n; ++i)
        LOG("%d: %d\n", i, v[i]);
#endif

    vector<int> dups(mx + 1);
    for (int i= 0; i < n; ++i)
        dups[v[i]]++;

    vector<int> dp(mx + 1);
    for (int i = 0; i < n; ++i)
        dp[v[i]]++;
    for (int i = 0; i < n; ++i)
    {
        LOG("processing %d:\n", v[i]);
        int j = 2;
        while (v[i] * j <= mx)
        {
            LOG("\tnum: %d, is: %d, could be: %d, ", v[i] * j, dp[v[i] * j], dp[v[i]] + dups[v[i] * j]);
            dp[v[i] * j] = max(dp[v[i] * j], dp[v[i]] + dups[v[i] * j]);
            LOG("now is: %d\n", dp[v[i] * j]);
            j++;
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
        result = max(result, dp[v[i]]);

#if DEBUG
    LOG("dp:\n");
    for (int i = 0; i < n; ++i)
        LOG("%d, %d: %d\n", i, v[i], dp[v[i]]);
#endif
    printf("%d\n", result);
}

