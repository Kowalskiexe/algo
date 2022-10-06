#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char s[(int)1e5 + 1];

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
    return fac[n] * power(fac[k] * fac[n - k] % M, M - 2) % M;
}

ll solve(ll zeros, ll ones)
{
    ll result = 0;
    for (ll i = 1; i <= min(zeros, ones); ++i)
    {
        LOG("for %lld: %lld, %lld\n", i, binom(zeros, i), binom(ones, i));
        result = (result + binom(zeros, i) * binom(ones, i) % M) % M;
    }
    return result;
}

int main()
{
    fac.resize((int)1e5 + 1);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= (int)1e5; ++i)
        fac[i] = fac[i - 1] * i % M;

#if DEBUG2
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("-> %lld\n", solve((ll)1e5/2, (ll)1e5/2));
#endif
    scanf("%s", s);
    int n = strlen(s);

        ll zeros = 0, ones = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            zeros++;
        else
            ones++;
    }
    LOG("zeros: %lld, ones: %lld\n", zeros, ones);
    ll result = solve(zeros, ones);
    printf("%lld\n", result);
}
