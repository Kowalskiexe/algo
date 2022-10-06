// too slow
#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

int n, a, b;

vector<ll> comb;
void solve(int nr, int s)
{
    for (int i = 1; i <= 6; ++i)
    {
        s += i;
        if (nr == n)
            comb[s]++;
        else
            solve(nr + 1, s);
        s -= i;
    }
}


int main()
{
    scanf("%d %d %d", &n, &a, &b);
    comb.resize(6 * n + 1);
    solve(1, 0);

#if DEBUG
    for (int i = 0; i < 6 * n + 1; ++i)
        LOG("%d: %lld\n", i, comb[i]);
#endif

    ll total = 0;
    for (int i = n; i <= 6 * n; ++i)
        total += comb[i];

    ll searched = 0;
    for (int i = a; i <= b; ++i)
        searched += comb[i];

    double out = round((double)searched / (double)total * 1e6) / 1e6;
    printf("%.6f\n", out);
}
