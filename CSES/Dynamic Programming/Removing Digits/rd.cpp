#include <bits/stdc++.h>

int n;

int main()
{
    scanf("%d", &n);

    int steps = 0;
    while (n > 0)
    {
        int maxdigit = n % 10;
        int tmp = n;
        while (tmp > 0)
        {
            int d = tmp % 10;
            if (d > maxdigit)
            {
                maxdigit = d;
                if (d == 9)
                    break;
            }
            tmp /= 10;
        }
        n -= maxdigit;
        steps++;
    }
    printf("%d\n", steps);
}
