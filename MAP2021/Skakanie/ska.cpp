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
vector<int> fnz;

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    fnz.resize(n);
    fnz[0] = 1;
    for (int i = 1; i < n; i++)
        fnz[i] = i;

    int curr = 0;
    ll result = 1;
    ll x = 1;
    while (true)
    {
        LOG("curr: %d, x: %lld\n", curr, x);

        if (curr == n - 1)
        {
            printf("%lld\n", result);
            return 0;
        }

        if (v[curr] == 0)
        {
            LOG("skipped from %d to %d\n", curr, fnz[curr]);
            curr = fnz[curr];
        }
        else
        {
            LOG("step from %d to %d\n", curr, curr + 1);
            x += v[curr];
            v[curr] = 0;
            fnz[curr] = fnz[curr + 1];
            curr += x;
        }

        if (curr >= n)
        {
            LOG("reset\n");
            result++;
            curr = 0;
            x = 1;
        }
        LOG("\n");
    }
}

