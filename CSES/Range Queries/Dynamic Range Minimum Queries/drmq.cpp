#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

ll n, q;

ll R;

vector<ll> tree;

void inline insert(int at, ll val)
{
    LOG("ins at: %lld\n", at + R - 1);
    at += R - 1;
    tree[at] = val;
    at /= 2;
    while (at > 0)
    {
        tree[at] = min(tree[at * 2], tree[at * 2 + 1]);
        at /= 2;
    }
}

ll inline query(int a, int b, int ca, int cb, int x)
{
    LOG("\tca: %d cb: %d x: %x\n", ca, cb, x);
    if (a <= ca && cb <= b)
    {
        LOG("\treturning (%d) %lld\n", x, tree[x]);
        return tree[x];
    }

    int mid = (ca + cb) / 2;
    ll out = LLONG_MAX;
    if (a <= mid)
        out = min(out, query(a, b, ca, mid, x * 2));
    if (b > mid)
        out = min(out, query(a, b, mid + 1, cb, x * 2 + 1));
    return out;
}

int main()
{
    scanf("%lld %lld", &n, &q);

    R = 1;
    while (R < n)
        R *= 2;
    LOG("n: %lld q: %lld R: %lld\n", n, q, R);

    tree.resize(R * 2);
    for (int i = 0; i < tree.size(); ++i)
        tree[i] = LLONG_MAX;

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
        int type, left, right;
        scanf("%d %d %d", &type, &left, &right);
        if (type == 1)
        {
            insert(left, right);
#if DEBUG
            LOG("insert at %d, val: %d\n", left, right);
            for (int i = 0; i < tree.size(); ++i)
                LOG("%d: %lld\n", i, tree[i]);
#endif
        }
        else
        {
            LOG("for %d %d:\n", left, right);
            ll res = query(left, right, 1, R, 1);
            printf("%lld\n", res);
        }
    }
}

