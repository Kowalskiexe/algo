#include <bits/stdc++.h>
using namespace std;

#if DEBUG 
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

#if DEBUGF
#define LOGF(...) printf(__VA_ARGS__)
#else
#define LOGF(...)
#endif

int n, x;

vector<pair<int, int>> v;

int inline bs(int a, int b, int k)
{
    while (a <= b)
    {
        int mid = (a + b) / 2;
        LOG("A: %d B: %d\n", a, b);
        if (v[mid].first == k)
            return mid;
        else if (v[mid].first > k)
            return bs(a, mid - 1, k);
        else
            return bs(mid + 1, b, k);
    }
    return -1;
}

int main()
{
    scanf("%d %d", &n, &x);
    LOG("n: %d x: %d\n", n, x);

    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        v.emplace_back(in, i);
    }
    sort(v.begin(), v.end());

#if DEBUG
    for (auto i : v)
        LOG("%d %d\n", i.first, i.second);
#endif

    for (int i = 0; i < n; ++i)
    {
        int& a = v[i].first;
        int b = x - a;
        int f = bs(0, v.size() - 1, b);
        LOG("a: %d b: %d f: %d\n", a, b, f);

        if (f != -1)
        {
            if (b == a)
            {
                if (v[f - 1].first == b)
                {
                    printf("%d %d\n", v[f - 1].second + 1, v[i].second + 1);
                    return 0;
                }
                if (v[f + 1].first == b)
                {
                    printf("%d %d\n", v[f + 1].second + 1, v[i].second + 1);
                    return 0;
                }
            }
            else
            {
                printf("%d %d\n", v[f].second + 1, v[i].second + 1);
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE\n");
}
