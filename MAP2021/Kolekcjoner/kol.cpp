#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int t;
int main()
{
    scanf("%d", &t);

    while (t--)
    {
        int a;
        ll k;
        scanf("%d %lld", &a, &k);
        for (int i = 0; i < a; ++i)
        {
            ll in;
            scanf("%lld", &in);
            k += in;
        }
        long double x = (-1 + sqrt(8 * k + 1)) / 2;
        x = floor(x);
        printf("%.0Lf\n", x - a);
    }
}

