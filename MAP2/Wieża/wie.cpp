#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll M = (ll)1e9 + 7;

ll inline power(ll b, ll e)
{
    if (e == 0) return 1;
    if (e == 1) return b % M;
    if (e % 2 == 0)
    {
        ll out = power(b, e / 2);
        return out * out % M;
    }
    else
        return b * power(b, e - 1) % M;
}

vector<ll> fac;

ll inline binom(ll n, ll k)
{
    LOG("\tbinom %lld over %lld\n", n, k);
    return fac[n] * power(fac[k] * fac[n - k] % M, M - 2) % M;
}


int n;

int main()
{
    fac.resize((int)1e6 + 1);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= (int)1e6; ++i)
        fac[i] = fac[i - 1] * i % M;

    scanf("%d", &n);
    vector<int> r((int)1e6 + 1);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        r[in]++;
    }

    ll result = 1;
    for (int i = 0; i <= (int)1e6; ++i)
    {
        if (r[i] > 0)
        {
            LOG("%d occurs %d times\n", i, r[i]);
            result = result * binom(n, r[i]) % M;
            n -= r[i];
        }
    }

    printf("%lld\n", result);
}
