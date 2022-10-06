#include <bits/stdc++.h>
using namespace std;

int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            for (int i = 2; i <= n; i += 2)
                printf("%d %d ", i, i - 1);
        }
        else
        {
            if (n == 1)
                printf("1");
            else
            {
                printf("3 1 2 ");
                for (int i = 5; i <= n; i += 2)
                    printf("%d %d ", i, i - 1);
            }
        }
        printf("\n");
    }
}
