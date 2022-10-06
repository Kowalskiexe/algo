#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
typedef complex<ll> C;
#define X real()
#define Y imag()

ll inline cross(C a, C b)
{
    return a.X * b.Y - a.Y * b.X;
}

bool inline ccmp(const C a, const C b)
{
    return cross(a, b) < 0;
}

ll n;
vector<C> v;

int main()
{
    scanf("%lld", &n);

    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        ll x0, y0, x1, y1;
        scanf("%lld %lld %lld %lld", &x0, &y0, &x1, &y1);
        int x = x1 - x0;
        int y = y1 - y0;
        if (x < 0)
        {
            x *= -1;
            y *= -1;
        }
        v[i] = {x, y};
    }

    sort(v.begin(), v.end(), ccmp);
#if DEBUG
    for (int i = 0; i < n; ++i)
        LOG("%d: %lld %lld\n", i, v[i].X, v[i].Y);
#endif
    ll paral = 0;
    ll rem = 0;
    C last = v[0];
    for (int i = 1; i < n; ++i)
    {
        if (cross(last, v[i]) == 0)
            paral++;
        else
        {
            paral++;
            LOG("%lld parals, rem: %lld\n", paral, paral * (paral - 1) / 2);
            last = v[i];
            rem += paral * (paral - 1) / 2;
            paral = 0;
        }
    }
    paral++;
    LOG("plus: %lld parals, rem: %lld\n", paral, paral * (paral - 1) / 2);
    rem += paral * (paral - 1) / 2;
    paral = 0;
    LOG("raw: %lld, rem: %lld\n", n * (n - 1) / 2, rem);
    ll out = n * (n - 1) / 2 - rem;
    printf("%lld\n", out);
}

