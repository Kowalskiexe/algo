#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<pair<int, int>> v;
int n, m;

int main()
{
    scanf("%d %d", &n, &m);

    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end());

    if (v[0].first != 0 || v[n - 1].second != m)
    {
        LOG("bad start/end\n");
        printf("NIE\n"); return 0;
    }
    int ml = v[0].second;
    for (int i = 1; i < n; ++i)
    {
        ml = max(ml, v[i - 1].second);
        if (v[i].first > ml)
        {
            LOG("bad: %d %d -> %d %d\n", v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
            printf("NIE\n");
            return 0;
        }
    }
    printf("TAK\n");
    return 0;
}

