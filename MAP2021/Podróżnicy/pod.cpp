#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll x, y, z, k;

int main()
{

    scanf("%lld %lld %lld %lld", &x, &y, &z, &k);
    if ((x + y + z) % 3 == 0)
    {
        ll mean = (x + y + z) / 3;
        LOG("mean: %lld\n", mean);
        ll out = 0;
        ll d = mean - x; // x + d = mean
        if (d % k != 0)
        {
            printf("-1\n");
            return 0;
        }
        if (d < 0) d = -d;
        out += d;

        d = mean - y;
        if (d % k != 0)
        {
            printf("-1\n"); return 0;
        }
        if (d < 0) d = -d;
        out += d;

        d = mean - z;
        if (d % k != 0)
        {
            printf("-1\n"); return 0;
        }
        if (d < 0) d = -d;
        out += d;

        out /= 2;
        out /= k;
        printf("%lld\n", out);
    }
    else
        printf("-1\n");
}
