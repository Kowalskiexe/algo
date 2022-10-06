#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

ll inline area(const vector<P>& p)
{
    ll sum = 0;
    for (int i = 0; i < p.size() - 1; ++i)
    {
        ll x = p[i + 1].X - p[i].X;
        ll y = p[i].Y + p[i + 1].Y;
        ll add = x * y;
        sum += add;
        LOG("%d %d: %lld * %lld = %lld, %lld\n", i, i + 1, x, y, add, sum);
    }
    sum += (p[0].X - p[p.size() - 1].X) * (p[p.size() - 1].Y + p[0].Y);
    if (sum < 0)
        sum = -sum;
    return sum;
}

int n;
int main()
{
    scanf("%d", &n);
    vector<P> p(n);
    for (int i = 0; i < n; ++i)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        p[i] = {x, y};
    }
#if DEBUG
    for (P i : p)
        LOG("%lld %lld\n", i.X, i.Y);
#endif
    printf("%lld\n", area(p));
}

