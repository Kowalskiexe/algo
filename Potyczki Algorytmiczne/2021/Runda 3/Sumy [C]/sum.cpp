#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<ll> v;
vector<ll> sor;

ll can_weight(ll w, int skip) // I bet it can be faster
{
    int i = 0;
    while (sor[i] < w && i < n)
    {
        if (i != skip)
            w += sor[i];
        i++;
    }
    return w;
}

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    sor = v;
    sort(sor.begin(), sor.end());

    ll biggest = sor[n - 1];

    int a = 0, b = n - 1;
    ll thres = LLONG_MAX;
    while (a <= b)
    {
        LOG("%d %d\n", a, b);
        int mid = (a + b) / 2;
        ll val = can_weight(sor[mid], mid);
        if (val > biggest && can_weight(sor[mid - 1], mid - 1) <= biggest)
        {
            thres = sor[mid];
            LOG("break at: %d\n", mid);
            break;
        }
        else if (val <= biggest)
            a = mid + 1;
        else
            b = mid;
    }
    LOG("threshold: %lld\n", thres);

    for (int i = 0; i < n; ++i)
    {
        if (v[i] >= thres)
            printf("T");
        else
            printf("N");
    }
    printf("\n");
}

