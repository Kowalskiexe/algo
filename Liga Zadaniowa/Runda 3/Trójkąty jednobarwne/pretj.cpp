#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll inline all(ll n)
{
    if (n == 3)
        return 1;
    if (n == 4)
        return 4;
    if (n == 5)
        return 10;
    ll out = 1;
    bool d = false;
    for (int i = n - 2; i <= n; ++i)
    {
        out *= i;
        if (out % 6 == 0 && !d)
        {
            out /= 6;
            d = true;
        }
    }
    return out;
}

int main()
{
    printf("ll preall[] = {");
    for (int i = 3; i <= 1000; ++i)
        printf("%lld,", all(i));
    printf("\b};\n");
}
