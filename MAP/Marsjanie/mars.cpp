#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int R;
vector<bool> t[1001];

int n, q;

void inline insert(int T, int index)
{
    int j = R + index;
    while (j > 0)
    {
        t[T][j] = true;
        j /= 2;
    }
}

void inline query(set<int>& o, int a, int b, int l = 0, int r = R - 1, int m = 1)
{
    LOG("a: %d b: %d l: %d r: %d m: %d\n", a, b, l, r, m);
    if (a <= l && r <= b)
    {
        for (int i = 1; i <= 1000; ++i)
            if (t[i][m])
                o.insert(i);
        return;
    }

    int mid = (l + r) / 2;
    if (a <= mid)
        query(o, a, b, l, mid, m * 2);
    if (b > mid)
        query(o, a, b, mid + 1, r, m * 2 + 1);
}

int main()
{
    scanf("%d %d", &n, &q);

    R = 1;
    while (R <= n)
        R *= 2;

    for (int i = 1; i <= 1000; ++i)
        t[i].resize(R * 2);

    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d", &t);
        insert(t, i);
    }

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        set<int> out;
        query(out, a, b);
        printf("%ld\n", out.size());
    }
}
