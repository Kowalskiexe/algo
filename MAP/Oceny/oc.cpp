#include <bits/stdc++.h>

int n;

int main()
{
    scanf("%d", &n);
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        if (in < last)
        {
            printf("NIE\n");
            return 0;
        }
        last = in;
    }
    printf("TAK\n");
}

