#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll M = (ll)1e9 + 7ll;
ll inline power(ll base, ll exp)
{
    if (exp == 0) return 1ll;
    if (exp == 1) return base % M;
    if (exp % 2 == 0)
    {
        ll out = power(base, exp / 2);
        return out * out % M;
    }
    else return base * power(base, exp - 1) % M;
}


ll inline fac(ll n)
{
    if (n == 1ll || n == 0ll)
        return 1ll;
    else
        return n * fac(n - 1) % M;
}

int n;
vector<int> v;
vector<int> c;

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    LOG("n: %d\n", n);
    LOG("v\n");
    for (int i = 0; i < n; ++i)
        LOG("%d ", v[i]);
    LOG("\n");

    if (n == 3)
    {
        if (v[0] != v[2])
        {
            printf("0\n");
            return 0;
        }
    }

    vector<int> dup_check(n + 1);
    for (int& i : dup_check)
        i = -1;

    for (int i = 0; i < n; ++i)
    {
        if (dup_check[v[i]] == -1)
            dup_check[v[i]] = i;
        else if (abs(dup_check[v[i]] - i) != 2)
        {
            LOG("dups\n");
            printf("0\n");
            return 0;
        }
    }
    LOG("no dups\n");

    c.resize(n);
    // left -> right
    c[1] = v[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (v[i - 1] == v[i + 1])
        {
            if (c[i] == 0 || c[i] == v[i - 1])
                c[i] = v[i - 1];
            else
            {
                printf("0\n");
                return 0;
            }
        }
        if (c[i - 1] == 0 && c[i + 1] != 0 && c[i + 1] != v[i])
        {
            if (c[i - 1] == 0 || c[i - 1] == v[i])
                c[i - 1] = v[i];
            else
            {
                printf("0\n");
                return 0;
            }
        }
        if (c[i + 1] == 0 && c[i - 1] != 0 && c[i - 1] != v[i])
        {
            if (c[i + 1] == 0 || c[i + 1] == v[i])
                c[i + 1] = v[i];
            else
            {
                printf("0\n");
                return 0;
            }
        }
    }
    LOG("after left->right\n");
    for (int i = 0; i < n; ++i)
        LOG("%d ", c[i]);
    LOG("\n");

    // left <- right
    c[n - 2] = v[n - 1];
    for (int i = n - 2; i > 0; --i)
    {
        LOG("v[%d]: %d c[%d]: %d c[%d]: %d\n",
                i, v[i], i - 1, c[i - 1], i + 1, c[i + 1]);
        if (v[i - 1] == v[i + 1])
        {
            if (c[i] == 0 || c[i] == v[i - 1])
                c[i] = v[i - 1];
            else
            {
                printf("0\n");
                return 0;
            }
        }
        if (c[i - 1] == 0 && c[i + 1] != 0 && c[i + 1] != v[i])
        {
            if (c[i - 1] == 0 || c[i - 1] == v[i])
                c[i - 1] = v[i];
            else
            {
                printf("0\n");
                return 0;
            }
        }
        if (c[i + 1] == 0 && c[i - 1] != 0 && c[i - 1] != v[i])
        {
            if (c[i + 1] == 0 || c[i + 1] == v[i])
                c[i + 1] = v[i];
            else
            {
                printf("0\n");
                return 0;
            }
        }
    }
    LOG("after both\n");
    for (int i = 0; i < n; ++i)
        LOG("%d ", c[i]);
    LOG("\n");

    for (int i = 1; i < n - 1; ++i)
    {
        if (c[i - 1] != 0 && c[i + 1] != 0 && c[i - 1] != v[i] && c[i + 1] != v[i])
        {
            printf("0\n");
            return 0;
        }
    }
    // processing
    vector<int> xe;
    vector<int> xo;
    for (int i = 1; i < n - 1; ++i)
    {
        if (c[i - 1] == 0 && c[i + 1] == 0)
        {
            if (i % 2 == 0)
                xe.push_back(i);
            else
                xo.push_back(i);
        }
    }
    vector<int> x;
    int last = -69;
    int strike = 0;
    for (int i = 0; i < (int)xe.size(); ++i) // xe
    {
        if (xe[i] == last + 2)
            strike++;
        else
        {
            if (strike != 0)
                x.push_back(strike);
            strike = 1;
        }
        last = xe[i];
    }
    if (strike != 0)
        x.push_back(strike);
    last = -69;
    strike = 0;
    for (int i = 0; i < (int)xo.size(); ++i) // xo
    {
        if (xo[i] == last + 2)
            strike++;
        else
        {
            if (strike != 0)
                x.push_back(strike);
            strike = 1;
        }
        last = xo[i];
    }
    if (strike != 0)
        x.push_back(strike);
    LOG("xo\n");
    for (int i : xe)
        LOG("%d ", i);
    LOG("\nxo\n");
    for (int i : xo)
        LOG("%d ", i);
    LOG("\nx\n");
    for (int i : x)
        LOG("%d ", i);
    LOG("\n");
    ll z = 0;
    for (int i = 1; i <= n; ++i)
        if (dup_check[i] == -1)
            z++;
    LOG("z: %lld\n", z);
    ll out = 1;
    for (int i : x)
        out = (out * ((ll)i + 1ll)) % M;
    out = out * fac(z) % M;
    printf("%lld\n", out);
}
