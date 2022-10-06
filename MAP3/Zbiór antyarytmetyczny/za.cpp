#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    if (n > 20)
    {
        printf("NIE\n");
        return 0;
    }
    if (n == 2)
    {
        printf("1 2\n");
        return 0;
    }
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    int sum = 4;
    printf("1 2 4 ");
    int last = 4;
    for (int i = 3; i < n; ++i)
    {
        last += sum;
        printf("%d ", last);
        sum = sum * 2 + 1;
    }
    printf("\n");
}

