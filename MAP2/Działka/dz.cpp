#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
typedef complex<ll> C;
#define X real()
#define Y imag()

ll cross(C a, C b)
{
    return (conj(a)*b).Y;
}

// < 0 <=> on right
bool crocmp(const C& a, const C& b)
{
    return cross(a, b) < 0;
}

vector<C> v;

int n;

int binar(C t)
{
    LOG("look for %lld %lld\n", t.X, t.Y);
    int a = 0, b = n + 1;
    while (a <= b)
    {
        int mid = (a + b) / 2;
        LOG("\tcmp: %lld %lld\n", v[mid].X, v[mid].Y);
        if (cross(t, v[mid]) <= 0 && cross(t, v[mid - 1]) > 0)
        {
            LOG("\tfound\n");
            return mid;
        }
        else if (cross(t, v[mid]) <= 0)
        {
            LOG("\tleft\n");
            b = mid;
        }
        else
        {
            LOG("\tright\n");
            a = mid + 1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    LOG("n: %d\n", n);

    v.resize(n + 2);
    v[0] = {(ll)1e9 + 1, 0ll};
    v[n + 1] = {0ll, (ll)1e9 + 1ll};
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v[i] = {x, y};
    }

    sort(v.begin(), v.end(), crocmp);
#if DEBUG
    for (int i = 0; i <= n + 1; ++i)
        LOG("%lld %lld\n",  v[i].X, v[i].Y);
#endif

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        C a = {x, y};
        int idx = binar(a);
        LOG("for %d %d -> %d\n", x, y, idx);
        if (idx != -1)
            printf("%d\n", n - idx + 1);
        else
            printf("0\n");
    }
}

