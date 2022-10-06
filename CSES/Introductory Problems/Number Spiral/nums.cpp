#include <stdio.h>

long long inline spiral(long long y, long long x)
{
    if (y >= x)
    {
        if (y % 2 == 0)
            return y * y - x + 1;
        else
            return (y - 1) * (y - 1) + x;
    }
    else
    {
        if (x % 2 == 0)
            return (x - 1) * (x - 1) + y;
        else
            return x * x - y + 1;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        long long y;
        long long x;
        scanf("%lld %lld", &y, &x);
        printf("%lld\n", spiral(y, x));
    }
}
