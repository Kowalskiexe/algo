#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if ((n + 1) * n / 2 % 2 != 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        if (n % 2 == 0)
        {
            printf("%d\n", n / 2);
            for (int i = 1; i < n / 2; i += 2)
                printf("%d %d ", i, n - i + 1);
            printf("\n%d\n", n / 2);
            for (int i = 2; i <= n / 2; i += 2)
                printf("%d %d ", i, n - i + 1);
        }
        else
        {
            printf("%d\n", n / 2 + 1);
            for (int i = 1; i <= n / 2; i += 2)
                printf("%d %d ", i, n - i);
            printf("\n%d\n", n / 2);
            for (int i = 2; i < n / 2; i += 2)
                printf("%d %d ", i, n - i);
            printf("%d", n);
        }
    }
    printf("\n");
}


