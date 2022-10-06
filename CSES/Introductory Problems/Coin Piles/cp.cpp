#include <stdio.h>

bool inline check(double a, double b)
{
    double y = (a - 2 * b) / (-3);
    double x = b - 2 * y;
    //printf("\ty: %f x: %f\n", y, x);
    return y == (long long)y && x == (long long)x && y >= 0 && x >= 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        long long a;
        long long b;
        scanf("%lld %lld", &a, &b);
        
        if (check(a, b))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
