#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    n /= 5;
    int trailing = n;
    while (n >= 5)
    {
        n /= 5;
        trailing += n;
    }

    printf("%d\n", trailing);
}
