#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll r[2'000'000];
ll n;
int main()
{
    scanf("%lld", &n);
    ll rt = 0;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            printf("%lld ", i);
            if (n / i != i)
            {
                r[rt] = n / i; rt++;
            }
        }
    }
    for (ll i = rt - 1; i >= 0; --i)
        printf("%lld ", r[i]);
}
    
