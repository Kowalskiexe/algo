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

ll cross(C a, C b)
{
    return (conj(a)*b).Y;
}


int main()
{
    int q;
    ll x1, y1, x2, y2, x3, y3;
    scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);
    C a = {x1, y1};
    C b = {x2, y2};
    C c = {x3, y3};
    ll area = abs(cross(b-a, c-a));
    LOG("area: %lld\n", area);

    scanf("%d", &q);
    int in = 0;
    for (int i = 0; i < q; ++i)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        C v = {x, y};
        ll a1 = abs(cross(b-a, v-a));
        ll a2 = abs(cross(v-a, c-a));
        ll a3 = abs(cross(c-b, v-b));
        if (area == a1 + a2 + a3)
        {
            in++;
            LOG("%lld %lld is in, %lld\n", x, y, a1 + a2 + a3);
            if (in == 3)
            {
                printf("TAK\n");
                return 0;
            }
        }
    }
    printf("NIE\n");
}

