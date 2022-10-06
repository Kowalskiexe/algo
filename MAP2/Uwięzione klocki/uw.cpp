#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll k;

int main()
{
    scanf("%lld", &k);

    ll out = 0;
    ll n = 1;
    ll p = 2;
    while (p < k)
    {
        out += (p / 2) * (k / p - 1);
        p *= 2;
        n++;
    }
    printf("%lld\n", out);
}
