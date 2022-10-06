#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n, m;

ll R;
vector<ll> fac_tree;
void inline update_fac_tree_from(ll idx)
{
    while (idx > 0)
    {
        idx /= 2;
        fac_tree[idx] = fac_tree[idx * 2] * fac_tree[idx * 2 + 1] % m;
    }
}

ll inline fac_without(ll without)
{
    ll idx = R + without - 1;
    fac_tree[idx] = 1;
    update_fac_tree_from(idx);

    ll out = fac_tree[1];

    idx = R + without - 1;
    fac_tree[idx] = without % m;
    update_fac_tree_from(idx);

    return out;
}

ll inline f(ll n)
{
    vector<ll> tmp(n + 1);
    tmp[3] = 1;
    for (ll i = 4; i <= n; ++i)
        tmp[i] = (tmp[i - 1] * (i - 1) % m + 1) % m;
    return tmp[n];
}

ll add(ll n)
{
    return (n - 1) * fac_without(2) % m;
}

int main()
{
    scanf("%lld %lld", &n, &m);
    if (n == 2ll)
    {
        printf("1\n");
        return 0;
    }

    R = 1;
    while (R < n)
        R *= 2;
    fac_tree.resize(R * 2);
    for (ll i = 0; i < R * 2; ++i)
        fac_tree[i] = 1;
    for (ll i = 0; i < n; ++i)
        fac_tree[R + i] = (i + 1) % m;
    for (ll i = 0; i < n; ++i)
        update_fac_tree_from(R + i);

    ll count = 0, out = 0;
    for (ll i = 1; i < n - 1; ++i)
    {
        count = (count + fac_without(n - i)) % m;
        if (count < 0)
            count += m;
        LOG("%lld occurs %lld times\n", i, count);
        out = (out + i * count % m) % m;
        if (out < 0)
            out += m;
    }
    count = (count + add(n)) % m;
    if (count < 0)
        count += m;
    count = (count - f(n) * n % m) % m;
    if (count < 0)
        count += m;
    LOG("%lld occurs %lld times\n", n - 1, count);
    out = (out + (n - 1) * count % m) % m;
    if (out < 0)
        out += m;
    printf("%lld\n", out);
}

