#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, q;

int R;
vector<ll> tree;

void inline insert(int i, int v)
{
    i += R - 1;
    tree[i] = v;
}

vector<ll> update;
ll inline query(int a, int l, int r, int x)
{
    LOG("\tquery %d| %d %d %d\n", a, l, r, x);
    if (update[x])
        tree[x] = update[x];
    if (l == r)
        return tree[x];
    int mid = (l + r) / 2;
    if (a <= mid)
        return query(a, l, mid, x * 2);
    else
        return query(a, mid + 1, r, x * 2 + 1);
}

void inline insert(int a, int b, int l, int r, int x, int v)
{
    printf("\tinsert %d %d: %d| %d %d %d\n", a, b, v, l, r, x);
    if (a <= l && r <= b)
    {
        update[x] = v;
        return;
    }

    int mid = (l + r) / 2;
    if (a <= mid)
        insert(a, b, l, mid, x * 2, v);
    if (b > mid)
        insert(a, b, mid + 1, b, x * 2 + 1, v);
}

int main()
{
    scanf("%d %d", &n, &q);

    R = 1;
    while (R < n)
        R *= 2;
    tree.resize(R * 2);
    update.resize(R * 2);

    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        insert(i, in);
    }
#if DEBUG
    for (int i = 1; i < tree.size(); ++i)
        LOG("%d: %lld\n", i, tree[i]);
#endif

    for (int i = 0; i < q; ++i)
    {
        int type;
        scanf("%d", &type);
        if (type == 2)
        {
            // query
            LOG("query\n");
            int a;
            scanf("%d", &a);
            printf("%lld\n", query(a, 1, R, 1));
        }
        else
        {
            // insert
            LOG("insert\n");
            int a, b, v;
            scanf("%d %d %d", &a, &b, &v);
            insert(a, b, 1, R, 1, v);
        }
    }
}
