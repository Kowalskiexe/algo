#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll inline power(ll base, ll power)
{
    ll result = 1;
    while (power)
    {
        result *= base;
        power--;
    }
    return result;
}


int inline quary(ll index)
{
    ll minus = 9;
    int digits = 1;
    while (index - minus * digits > 0) // mathematicaly index > minus * digits
    {
        index -= minus * digits;
        minus *= 10;
        digits++;
    }
    index--;
    ll number = index / digits;
    number += power(10, digits - 1);
    ll dx = index % digits;
    LOG("\tdigits: %d index: %lld number: %lld dx: %lld",
           digits, index, number, dx);
    // lift out the needed digit
    ll lo = digits - 1 - dx;
    while (lo)
    {
        number /= 10;
        lo--;
    }
    int result = number % 10;
    LOG(" result: %d\n", result);
    return result;
}

int q;

int main()
{
    scanf("%d", &q);

    for (int i = 0; i < q; ++i)
    {
        ll k;
        scanf("%lld", &k);
        printf("%d\n", quary(k));
    }
}
