#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<int> v;

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    int zeros = 0;
    int result = 0;
    while (zeros < n)
    {
        zeros = 0;
        int odd = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] % 2 == 1)
            {
                odd++;
                result++;
                LOG("dec\n");
                v[i]--;
            }
            if (v[i] == 0)
                zeros++;
        }
#if DEBUG
        for (int i : v)
            LOG("%d ", i);
        LOG("\n");
#endif
        if (odd == 0 && zeros != n)
        {
            LOG("div\n");
            result++;
            for (int i = 0; i < n; ++i)
                v[i] /= 2;
        }
#if DEBUG
        for (int i : v)
            LOG("%d ", i);
        LOG("\n");
#endif

    }
    printf("%d\n", result);
}

