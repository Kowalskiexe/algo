#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

vector<int> v;
vector<ll> sums;
int n;

int bin(int l, int r, ll val)
{
    int a = l, b = r;
    while (a <= b)
    {
        int mid = (a + b) / 2;
        ll found = sums[mid] - sums[l];
        LOG("\ta: %d b: %d v: %lld f: %lld\n", a, b, val, found);
        if (found == val)
        {
            return mid;
        }
        if (found < val)
        {
            // right
            a = mid + 1;
        }
        else
        {
            // left
            b = mid - 1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);

    sums.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        sums[i] = sums[i - 1] + v[i];

#if DEBUG
    LOG("sums:\n");
    for (ll i : sums)
        LOG("%lld\n", i);
#endif

    for (int i = 1; i < sums.size(); ++i)
    {
        LOG("trying %lld\n", sums[i]);
        int count = 0;
        int last = 0;
        while (last < n)
        {
            int x = bin(last, n, sums[i]);
            LOG("found %d\n", x);
            if (x == -1)
            {
                goto big_break;
            }
            count++;
            last = x;
        }
        printf("%d\n", count);
        return 0;
        big_break:
        int rfasfd;
    }
    printf("1\n");
}
