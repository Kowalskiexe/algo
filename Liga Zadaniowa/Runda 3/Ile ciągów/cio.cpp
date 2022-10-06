#include <bits/stdc++.h>

using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

const ll M = 1e9 + 7;

ll n;
/*
ll inline fact(ll k)
{
    ll out = 1;
    for (int i = 2; i <= k; ++i)
        out = (out * i) % M;
    return out;
}
*/
ll inline power(ll base, ll k)
{
    if (k == 0) return 1;
    if (k == 1) return base;
    if (k % 2 == 0)
    {
        ll half = power(base, k / 2);
        return (half * half) % M;
    }
    else
        return (base * power(base, k - 1)) % M;
}
/*
ll inline count(ll k)
{
    ll out = 1;
    for (int i = 1; i < k; ++i)
        out = (out * (n - i)) % M;
    ll b = fact(k - 1);
    out = (out * power(b, M - 2)) % M;
    return out;
}
*/
int main()
{
    scanf("%lld", &n);
    /*
    ll out = 0;
    for (ll i = 1; i <= n / 2; ++i)
    {
        LOG("\t%lld\n", i);
        out += count(i);
        out %= M;
    }
    out = (out * 2) % M;
    if (n % 2 == 1)
        out = (out + count(n / 2 + 1)) % M;
    printf("%lld\n", out);
    */
    printf("%lld\n", power(2, n - 1));
}

    
