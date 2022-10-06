#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

int R;
vector<ll> tree;

void inline insert(int at, int val)
{
    at += R - 1;
    tree[at] = val;
    at /= 2;
    while (at > 0)
    {
        tree[at] = tree[at * 2] + tree[at * 2 + 1];
        at /= 2;
    }
}

ll inline query(int l, int r, int cl, int cr, int x)
{
    LOG("\t%d %d: %d\n", cl, cr, x);
    if (l <= cl && cr <= r)
    {
        LOG("\treturning (%d) %lld\n", x, tree[x]);
        return tree[x];
    }

    int mid = (cl + cr) / 2;
    ll out = 0;
    if (l <= mid)
        out += query(l, r, cl, mid, x * 2);
    if (r > mid)
        out += query(l, r, mid + 1, cr, x * 2 + 1);
    return out;
}

int n, q;
int main()
{
    scanf("%d %d", &n, &q);
    R = 1;
    while (R < n)
        R *= 2;
    tree.resize(R * 2);

    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        insert(i, in);
    }
#if DEBUG
    for (int i = 0; i < tree.size(); ++i)
        LOG("%d: %lld\n", i, tree[i]);
#endif

    for (int i = 0; i < q; ++i)
    {
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1)
            insert(a, b);
        else
        {
            LOG("for: %d %d\n", a, b);
            printf("%lld\n", query(a, b, 1, R, 1));    
        }
    }
}

