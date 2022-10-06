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

int n, m;

ll inline cross(const P& a, const P& b)
{
    return a.X * b.Y - b.X * a.Y;
}

// 2 - inside
// 1 - on boundary
// 0 - outside 
int inline do_intersect(const P& point, const P& ray, const P& a2, const P& b2)
{
    if (point == a2 || point == b2)
        return 1;

    ll pToA = cross(ray - point, a2 - point);
    ll pToB = cross(ray - point, b2 - point);
    ll c3 = cross(b2 - a2, point - a2);
    ll c4 = cross(b2 - a2, ray - a2);
    LOG("\t%lld %lld %lld %lld\n", pToA, pToB, c3, c4);

    if (pToA == 0 && pToB == 0) // are on the same line
    {
        array<P, 4> p = {point, ray, a2, b2};
        sort(p.begin(), p.end(), [](const P& a, const P& b) {
            if (a.X == b.X)
                return a.Y < b.Y;
            return a.X < b.X;
        });
        if ((p[0] == point && p[1] == ray) || (p[0] == ray && p[1] == point) || (p[0] == a2 && p[1] == b2) || (p[0] == b2 && p[1] == a2))
            return 1;
        return 0;
    }

    if (signbit(pToA) != signbit(pToB) && (c3 == 0 || c4 == 0))
    {
        LOG("\tA\n");
        return 1;
    }
    if (signbit(c3) != signbit(c4) && (pToA == 0 || pToA == 0))
    {
        LOG("\tB\n");
        return 2;
    }
    if ((signbit(pToA) != signbit(pToB)) && (signbit(c3) != signbit(c4)))
        return 2;
    return 0;
}

// 2 - inside
// 1 - on boundary
// 0 - outside
int inline is_inside(const vector<P>& poly, P point)
{
    LOG("point: %lld %lld\n", point.X, point.Y);
    P ray = {(ll)-1e2, 0};
    ray += point;
    int count = 0;
    for (int i = 0; i < poly.size() - 1; ++i)
    {
        int di = do_intersect(point, ray, poly[i], poly[i + 1]);
        if (di > 0)
            LOG("intersection with %lld %lld - %lld %lld   %d\n",
                    poly[i].X, poly[i].Y, poly[i + 1].X, poly[i + 1].Y, di);
        if (di == 1)
            return 1;
        if (di == 2)
            count++;
    }
    int di = do_intersect(point, ray, poly[poly.size() - 1], poly[0]);
    if (di > 0)
    {
        int i = poly.size() - 1;
        LOG("intersection with %lld %lld - %lld %lld   %d\n",
            poly[i].X, poly[i].Y, poly[0].X, poly[0].Y, di);
    }
    if (di == 1)
        return 1;
    if (di == 2)
        count++;
    if (count % 2 == 0)
        return 0;
    else
        return 2;
}

int main()
{
    scanf("%d %d", &n, &m);
    vector<P> p(n);
    for (int i = 0; i < n; ++i)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        p[i] = {x, y};
    }

    for (int i = 0; i < m; ++i)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        P point = {x, y};
        switch(is_inside(p, point))
        {
            case 2:
                printf("INSIDE\n");
                break;
            case 1:
                printf("BOUNDARY\n");
                break;
            case 0:
                printf("OUTSIDE\n");
                break;
        }
    }
}

