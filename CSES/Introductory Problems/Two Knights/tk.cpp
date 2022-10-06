#include <stdio.h>
long long inline q(long long n)
{
    return (n*n*(n*n - 1))/2 - 4 * (n - 1) * (n - 2);
}

int main()
{
    int k;
    scanf("%d", &k);
    
    for (int i = 1; i <= k; ++i)
    {
        printf("%lld\n", q(i));
    }
}
