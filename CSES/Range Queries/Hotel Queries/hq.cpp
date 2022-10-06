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

int n, m;

void inline insert(int pos, int val)
{
    pos += R - 1;
    tree[pos] = val;
    while (pos > 0)
    {
        pos /= 2;
        tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
    }
}

int inline query(int val)
{
    int l = 1, r = R, x = 1;

    if (R == 1)
    {
        if (tree[1] >= val) return 1;
        else return 0;
    }
    while (l != r)
    {
        int mid = (l + r) / 2;
        if (tree[x * 2] >= val)
        {
            x *= 2;
            r = mid;
        }
        else if (tree[x * 2 + 1] >= val)
        {
            x = 2 * x + 1;
            l = mid + 1;
        }
        else
            return 0;
    }
    return x - R + 1;
}

int main()
{
    scanf("%d %d", &n, &m);

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
        LOG("%d: %d\n", i, tree[i]);
#endif

    for (int i = 0; i < m; ++i)
    {
        int in;
        scanf("%d", &in);
        int out = query(in);
        LOG("for %d -> %d\n", in, out);
        printf("%d ", out);
        int rem = tree[out + R - 1] - in;
        if (out != 0)
            insert(out, rem);
#if DEBUG
    for (int i = 0; i < tree.size(); ++i)
        LOG("%d: %d\n", i, tree[i]);
    LOG("\n");
#endif
    }
    printf("\n");
}
