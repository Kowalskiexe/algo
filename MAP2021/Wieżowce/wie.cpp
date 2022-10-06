#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll R;
vector<int> tree;

int n, q;

void inline insert(int id, int val)
{
    id += R - 1;
    tree[id] = val;
    id /= 2;
    while (id > 0)
    {
        tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
        id /= 2;
    }
}

void inline query(int l, int r, int a, int b, int x, vector<pair<int, int>>& out)
{
    LOG("\tquery %d %d | %d %d %d\n", l, r, a, b, x);
    if (l <= a && b <= r)
    {
        out.emplace_back(x, b - a + 1);
        return;
    }

    int mid = (a + b) / 2;
    if (l <= mid)
        query(l, r, a, mid, x * 2, out);
    if (r > mid)
        query(l, r, mid + 1, b, x * 2 + 1, out);
}

void inline descend(int x, int size, int k, int& out)
{
    if (tree[x] <= k) out += size;
    else if (size != 1)
    {
        descend(x * 2, size / 2, k, out);
        descend(x * 2 + 1, size / 2, k, out);
    }
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
#if DEBUG
    LOG("tree:\n");
    for (int i = 1; i < 2 * R; ++i)
        LOG("%d: %d\n", i, tree[i]);
    LOG("\n");
#endif

    for (int i = 0; i < q; ++i)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        vector<pair<int, int>> points;
        query(l, r, 1, R, 1, points);
#if DEBUG
        LOG("for %d %d %d:\n", l, r, k);
        LOG("x: size\n");
        for (auto u : points)
            LOG("%d: %d\n", u.first, u.second);
#endif
        int out = 0;
        for (auto u : points)
            descend(u.first, u.second, k, out);
        LOG("RESULT: ");
        printf("%d\n", out);
    }
}

