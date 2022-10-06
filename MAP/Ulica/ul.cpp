#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, to, from;

int R;
vector<bool> t;

void inline insert(int a, int b, int l = 0, int r = R - 1, int m = 1)
{
    LOG("a: %d b: %d l: %d r: %d m: %d\n", a, b, l, r, m);
    if (a <= l && r <= b)
    {
        LOG("found %d %d for %d %d m: %d\n", l, r, a, b, m);
        t[m] = true;
        return;
    }

    int mid = (l + r) / 2;
    if (a <= mid)
        insert(a, b, l, mid, m * 2);
    if (b > mid)
        insert(a, b, mid + 1, r, m * 2 + 1);
    
    //t[m] = t[m * 2] || t[m * 2 + 1];
}

bool inline query(int index)
{
    int l = 0, r = R - 1, m = 1;
    while (l < r)
    {
        if (t[m])
            return true;
        int mid = (l + r) / 2;    
        if (index <= mid)
        {
            r = mid;
            m = m * 2;
        }
        else
        {
            l = mid + 1;
            m = m * 2 + 1;
        }
    }

    return t[index + R];
}

int main()
{
    scanf("%d %d %d", &n, &to, &from);
    LOG("from: %d to: %d\n", from, to);

    R = 1;
    while (R <= max(to, from))
        R *= 2;
    LOG("R: %d\n", R);

    t.resize(R * 2 + 1);

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        LOG("%d %d\n", a, b);
        a = min(a, R);
        b = min(b, R);
        insert(a, b);
        LOG("\n");
    }

#if DEBUG
    for (int i = 0; i <= max(from, to); ++i)
        LOG("%d ", query(i));
    LOG("\n");
#endif

    vector<int> not_lit;
    not_lit.reserve(max(from, to));

    if (from < to)
    {
        for (int i = from; i <= to; ++i)
            if (!query(i))
                not_lit.push_back(i);
    }
    else
    {
        for (int i = from; i >= to; --i)
            if (!query(i))
                not_lit.push_back(i);
    }
    printf("%ld\n", not_lit.size());
    for (int i : not_lit)
        printf("%d ", i);
    printf("\n");
}
