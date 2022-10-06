#include <bits/stdc++.h>


using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
int h[1'000'002];
int pl[1'000'002];
int jl[1'000'002];
int pr[1'000'002];
int jr[1'000'002];
int m[1'000'002];

int main()
{
    scanf("%d", &n);

    h[0] = INT_MAX;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    h[n + 1] = INT_MAX;

    // left
    for (int i = 1; i <= n; ++i)
    {
        if (h[i - 1] > h[i])
        {
            pl[i] = i - 1;
            jl[i] = jl[i - 1] + 1;
        }
        else
        {
            int pos = pl[i - 1];
            while (h[pos] <= h[i])
                pos = pl[pos];
            pl[i] = pos;
            jl[i] = jl[pos] + 1;
        }
    }

    // right
    for (int i = n; i >= 1; --i)
    {
        if (h[i + 1] > h[i])
        {
            pr[i] = i + 1;
            jr[i] = jr[i + 1] + 1;
        }
        else
        {
            int pos = pr[i + 1];
            while (h[pos] <= h[i])
                pos = pr[pos];
            pr[i] = pos;
            jr[i] = jr[pos] + 1;
        }
    }

    // both
    for (int i = 1; i <= n; ++i)
        m[i] = max(jl[i], jr[i]);

#if DEBUG
    LOG("h:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", h[i]);
    // left
    LOG("\npl:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", pl[i]);
    LOG("\njl:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", jl[i]);
    // right
    LOG("\npr:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", pr[i]);
    LOG("\njr:\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", jr[i]);
    LOG("\n");
#endif
    // both
    LOG("\nm:\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", m[i]);
    printf("\n");
}
