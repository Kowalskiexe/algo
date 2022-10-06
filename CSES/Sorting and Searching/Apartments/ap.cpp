#include <bits/stdc++.h>

using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, k;
vector<int> apart;
vector<int> appli;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    LOG("n(appli): %d m(apart): %d k: %d\n", n, m, k);

    appli.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &appli[i]);

    apart.resize(m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &apart[i]);

    sort(appli.begin(), appli.end());
    sort(apart.begin(), apart.end());

#if DEBUG
    LOG("appli:\n");
    for (int i : appli)
        LOG("%d ", i);
    LOG("\napart:\n");
    for (int i : apart)
        LOG("%d ", i);
    LOG("\n");
#endif

    int result = 0;
    for (int i = 0, j = 0; j < m;)
    {
        int diff = appli[i] - apart[j];
        if (-k <= diff && diff <= k)
        {
            result++;
            i++;
            j++;
        }
        if (diff < 0) i++;
        if (diff > 0) j++;
    }
    printf("%d\n", result);
}

