#include <bits/stdc++.h>

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

bool inline is_prime(int n)
{
    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i+= 2)
        if (n % i == 0)
            return false;
    return true;
}

int inline next_prime(int n)
{
    int i = n + 1;
    while (!is_prime(i))
        i++;
    return i;
}

int main()
{
    scanf("%d", &n);

    int div = 2;
    int result = 0;
    while (div <= n)
    {
        LOG("prime: %d\n", div);
        while (n % div == 0)
        {
            n /= div;
            result++;
        }
        div = next_prime(div);
    }
    printf("%d\n", result);
}
