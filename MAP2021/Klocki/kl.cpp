#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;


int main()
{
    scanf("%d", &n);

    ll last = -1;
    for (int i = 0; i < n; ++i)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        if (x == y)
        {
            if (last == -1)
            {
                printf("%lld\n", x);
                last = x;
            }
            else
            {
                last = gcd(x, last);
                printf("%lld\n", last);
            }
        }
        else
        {
            for (int j = i; j < n; ++j)
                printf("1\n");
            return 0;
        }
    }
}

