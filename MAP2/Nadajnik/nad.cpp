#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<ll> v;
vector<ll> s;

ll inline S(int a, int b)
{
    if (a == 0)
        return s[b];
    else
        return s[b] - s[a - 1];
}

int main()
{
    scanf("%d", &n);

    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    s.resize(n);
    s[0] = v[0];
    for (int i = 1; i < n; ++i)
        s[i] = s[i - 1] + v[i];
#if DEBUG
    LOG("in:\n");
    for (int i = 0; i < n; ++i)
        LOG("%d: %lld\n", i, v[i]);
    LOG("S:\n");
    for (int i = 0; i < n; ++i)
        LOG("%d: %lld\n", i, s[i]);
#endif

    ll A = 0;
    for (ll p = n, i = 0; i < n; ++i, --p)
        A += p * v[i];

    ll result = A;
    for (int i = 1; i < n; ++i)
    {
        LOG("A: %lld ", A);
        ll B = A - S(0, i - 1) + S(i, n - 1);
        result = max(result, B);
        LOG("B: %lld\n", B);
        A = B;
    }
    printf("%lld\n", result);
}

