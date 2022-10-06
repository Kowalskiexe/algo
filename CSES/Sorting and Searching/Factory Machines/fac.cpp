#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n, c;
vector<ll> e;

ll f(ll t)
{
    ll out = 0;
    for (ll i : e)
        out += t / i;
    return out;
}

int main()
{
    scanf("%lld %lld", &n, &c);
    e.resize(n);
    for (ll i = 0; i < n; ++i)
        scanf("%lld", &e[i]);
    ll shorts = LLONG_MAX;
    for (ll i : e)
        shorts = min(shorts, i);

    ll a = 0, b = shorts * c;
    while (a <= b)
    {
        ll mid = (a + b) / 2;
        ll fm = f(mid);
        LOG("trying %lld -> %lld\n", mid, fm);
        if (f(mid - 1) < c && fm >= c)
        {
            printf("%lld\n", mid);
            return 0;
        }
        else if (fm >= c)
            // left
            b = mid;
        else
            // right
            a = mid + 1;
    }
    printf("not found\n");
}
