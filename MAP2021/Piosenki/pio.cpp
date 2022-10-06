#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int q;

const ll M = 1e9l + 7;

ll inline power(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2 == 0)
    {
        ll out = power(base, exp / 2);
        return (out * out) % M;
    }
    else
    {
        return (power(base, exp - 1) * base) % M;
    }
}

int main()
{
    LOG("%lld\n", M);
    scanf("%d", &q);
    while (q--)
    {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        if (n == 0)
            printf("0\n"); 
        else
            printf("%lld\n", (k * power(k - 1, n - 1)) % M);
    }
}

