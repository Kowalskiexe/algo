// works
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

ll inline cross(P a, P b)
{
    return a.X * b.Y - a.Y * b.X;
}

bool inline do_intersect(P a1, P b1, P a2, P b2)
{
    if (a1 == a2 || a1 == b2 || b1 == a2 || b1 == b2)
    {
        LOG("case 1\n");
        return true;
    }
    ll c1 = cross(b1 - a1, a2 - a1);
    ll c2 = cross(b1 - a1, b2 - a1);
    ll c3 = cross(b2 - a2, a1 - a2);
    ll c4 = cross(b2 - a2, b1 - a2);
    
    if (c1 == 0 && c2 == 0)
    {
        LOG("case 3\n");
        vector<P> p(4);
        p[0] = a1;
        p[1] = b1;
        p[2] = a2;
        p[3] = b2;
        sort(p.begin(), p.end(), [](const P& a, const P& b){
            if (a.X == b.X)
                return a.Y < b.Y;
            return a.X < b.X;
        });
#if DEBUG
        for (P i : p)
            LOG("%lld %lld, ", i.X, i.Y);
        LOG("\n");
#endif
        if ((p[0] == a1 && p[1] == b1) || (p[0] == b1 && p[1] == a1))
            return false;
        if ((p[0] == a2 && p[1] == b2) || (p[0] == b2 && p[1] == a2))
            return false;
        return true;
    }
    if ((signbit(c1) != signbit(c2) || c1 == 0 || c2 == 0) && (signbit(c3) != signbit(c4) || c3 == 0 || c4 == 0))
    {
        LOG("case 1\n");
        return true;
    }
    return false;
}

int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll a1x, a1y, b1x, b1y, a2x, a2y, b2x, b2y;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",
                &a1x, &a1y, &b1x, &b1y, &a2x, &a2y, &b2x, &b2y);
        P a1 = {a1x, a1y}, b1 = {b1x, b1y}, a2 = {a2x, a2y}, b2 = {b2x, b2y};
        if (do_intersect(a1, b1, a2, b2))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
