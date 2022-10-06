#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, q;

int R;
vector<ll> tree;

void insert(int i, int v)
{
    i += R - 1;
    tree[i] = v;
    i /= 2;
    while (i > 0)
    {
        tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
        i /= 2;
    }
}

ll inline query(int a, int b, int l, int r, int x)
{
    if (a <= l && r <= b) return tree[x];

    int mid = (l + r) / 2;
    ll out = 0;
    if (a <= mid)
        out ^= query(a, b, l, mid, x * 2);
    if (b > mid)
        out ^= query(a, b, mid + 1, r, x * 2 + 1);
    return out;
}

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

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        ll out = query(a, b, 1, R, 1);
        //if (out == 0)
            //out = -1;
        printf("%lld\n", out);
    }
}
