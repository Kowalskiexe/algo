#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

ll cross(const P& a, const P& b)
{
    return a.X * b.Y - a.Y * b.X;
}

int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll x1, y1, x2, y2, x3, y3;
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);
        ll xl = x2 - x1;
        ll yl = y2 - y1;
        ll xp = x3 - x1;
        ll yp = y3 - y1;
        ll c = cross({xl, yl}, {xp, yp});
        if (c < 0)
            printf("RIGHT\n");
        if (c == 0)
            printf("TOUCH\n");
        if (c > 0)
            printf("LEFT\n");
    }
}
