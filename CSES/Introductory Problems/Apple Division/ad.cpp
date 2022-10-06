#include <stdio.h>
#include <cstring>
#include <climits>

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif 

long long inline abs(long long n)
{
    if (n < 0)
        return -n;
    else
        return n;
}

long long quick_power(long long base, int power)
{
    // doesn't check for 0
    if (power == 1)
        return base;
    if (power % 2 == 0)
    {
        long long tmp = quick_power(base, power / 2);
        return tmp * tmp;
    }
    else
        return base * quick_power(base, power - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int t[20];
    memset(t, 0, 20 * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);

    if (n == 1)
    {
        printf("%d\n", t[0]);
        return 0;
    }

    long long min_diff = LLONG_MAX;
    long long tries = quick_power(2, n - 1); // not excatly
    for (long long i = 1; i < tries; ++i)
    {
        long long first = 0;
        long long second = 0;
        for (int j = 0; j < n; ++j)
        {
            bool add = i & (1 << j);
            LOG("%d", add);
            if (add)
                first += t[j];
            else
                second += t[j];
        }
        long long diff = abs(first - second);
        if (diff < min_diff)
            min_diff = diff;
        LOG(" f:%lld s:%lld  d:%lld\n", first, second, diff);
    }
    printf("%lld\n", min_diff);
}

