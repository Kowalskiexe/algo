#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll M = 1e9 + 7;

int n, m;

ll inline con(int x)
{
    if (x % 2 == 0)
        return x * (x + 2) / 4;
    else
        return (x + 1) * (x + 1) / 4;
}

ll inline solve(int i0, int v0, int i1, int v1)
{
    LOG("solve: i0: %d v0: %d i1: %d v1: %d\n", i0, v0, i1, v1);
    int y = abs(v1 - v0);
    int x = i1 - i0 - y + 1;
    LOG("x: %d y: %d\n", x, y);
    
    if (y > x)
    {
        return -1;
    }

    // cons
    ll out = (con(x - 2) * 2) % M;
    LOG("cons: %lld\n", out);

    // mid
    out = (out + x * (y + 1)) % M;
    LOG("mid: %lld\n", out);

    // under
    int u = x - v0 - v1;
    if (u > 0)
        out = (out - con(u)) % M;
    LOG("under: %lld\n", out);

    // over
    int o = x - (m - v0) - (m - v1);
    LOG("o: %d\n", o);
    if (o > 0)
        out = (out - con(o - 2)) % M;
    LOG("over: %lld\n", out);

    // taken
    out -= 2;
    LOG("taken: %lld\n", out);

    return out;
}

int main()
{
    scanf("%d %d", &n, &m);
    LOG("n: %d m: %d\n", n, m);
    int i0 = 0;
    int v0 = 0;
    int lv = -1;
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        int v;
        scanf("%d", &v);
        if (v != 0 && lv == 0)
        {
            ll sol = solve(i0, v0, i, v);
            if (sol == -1)
            {
                printf("0\n");
                return 0;
            }
            res = (res + sol) % M;
        }

        if (v != 0)
        {
            v0 = v;
            i0 = i;
        }
        lv = v;
    }
    printf("%lld\n", res);
}
