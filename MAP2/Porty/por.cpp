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
vector<int> arr;

int inline query(int a, int b, int occ)
{
    LOG("q: %d %d %d\n", a, b, occ);
    vector<bool> check((int)1e6 + 1);
    for (int i = a - 1; i < b; ++i)
    {
        if (check[v[i]])
        {
            LOG("%d checked\n", v[i]);
            continue;
        }
        int count = 1;
        int idx = i;
        while (arr[idx] < b && arr[idx] != 0)
        {
            LOG("\tidx: %d\n", idx);
            idx = arr[idx];
            count++;
        }
        LOG("%d is %d times in [%d %d]\n", v[i], count, a, b);
        if (count == occ)
        {
            LOG("out: %d\n", v[idx]);
            return v[idx];
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &n);

    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    vector<bool> pro((int)1e6 + 1);

    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        if (!pro[v[i]])
        {
            pro[v[i]] = true;
            int last = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (v[j] == v[i])
                {
                    arr[last] = j;
                    last = j;
                }
            }
        }
    }
#if DEBUG
    for (int i = 0; i < n; ++i)
        LOG("%d ", v[i]);
    LOG("\n");
    for (int i = 0; i < n; ++i)
        LOG("%d ", arr[i]);
    LOG("\n");
#endif
    ll q;
    scanf("%lld", &q);
    for (ll i = 0; i < q; ++i)
    {
        int a, b, o;
        scanf("%d %d %d", &a, &b, &o);
        printf("%d\n", query(a, b, o));
    }
}

