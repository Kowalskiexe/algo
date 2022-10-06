#include <stdio.h>

const long long M = 1'000'000'007;

long long inline power(long long base, long long pow)
{
    if (pow == 0)
        return 1;
    if (pow == 1)
        return base % M;
    if (pow % 2 == 0)
    {
        long long half = power(base, pow / 2);
        return (half * half) % M;
    }
    else
    {
        return (base * power(base, pow - 1)) % M;
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);

    printf("%lld\n", power(2, n));
}
