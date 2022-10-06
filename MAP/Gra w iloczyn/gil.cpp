#include <bits/stdc++.h>

typedef long long ll;
int A, B, C;

int main()
{
    scanf("%d %d %d", &A, &B, &C);

    ll move = 0;
    while (true)
    {
        for (ll i = 0; i < move; ++i)
        {
            if ((A + i) * (B + move - i) > C)
            {
                if (move % 2 == 1)
                    printf("Tomek\n");
                else
                    printf("Michal\n");
                return 0;
            }
        }
        move++;
    }
}

