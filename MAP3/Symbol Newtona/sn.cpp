#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll m = 1e9 + 7;

ll facn, fack, facnk;

ll inline power(ll base, ll exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return base;
    if (exp % 2 == 0)
    {
        ll out = power(base, exp / 2);
        return out * out % m;
    }
    else
        return base * power(base, exp - 1) % m;
}

ll inline from_to(ll from, ll to)
{
    ll out = 1;
    for (ll i = from; i <= to; ++i)
        out = out * i % m;
    return out;
}

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);

    ll last = 1;
    if (n - k == 1 || n - k == 0)
        facnk = 1;
    for (ll i = 2; i <= n - k; ++i)
        last = last * i % m;
    facnk = last;
    LOG("nk: %lld\n", facnk);

    ll nom = from_to(k + 1, n);
    LOG("nom: %lld\n", nom);
    ll result = nom * power(facnk, m - 2) % m;
    printf("%lld\n", result);
}

