#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

int main()
{
    scanf("%d", &n);

    int ones = 0;
    for (int i = 0; i < n * 8; ++i)
    {
        char in;
        scanf(" %c", &in);
        if (in == '1')
            ones++;
    }
    LOG("ones: %d\n", ones);
    int ones_per_let = ones / n;
    int residual = ones % n;
    LOG("opr: %d res: %d\n", ones_per_let, residual);
    if (ones_per_let < 3)
    {
        printf("NIE\n");
        return 0;
    }
    if (ones_per_let == 6 && residual > 0)
    {
        printf("NIE\n");
        return 0;
    }
    if (ones_per_let > 6)
    {
        printf("NIE\n");
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        int let = ones_per_let;
        if (i < residual)
            let++;
        switch (let)
        {
            case 3:
                printf("a");
                break;
            case 4:
                printf("c");
                break;
            case 5:
                printf("g");
                break;
            case 6:
                printf("o");
                break;
        }
    }
    printf("\n");
}
