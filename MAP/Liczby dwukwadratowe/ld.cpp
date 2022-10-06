#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int q;

int t[3000002];
int R;
void inline insert(int index)
{
    int j = index + R;
    if (t[j] == 1) return;
    while (j > 0)
    {
        t[j]++;
        j /= 2;
    }
}

int inline query(int a, int b, int l = 0, int r = R - 1, int m = 1)
{
    if (a <= l && r <= b)
    {
        return t[m];
    }

    int mid = (l + r) / 2;
    int out = 0;
    if (a <= mid)
        out += query(a, b, l, mid, m * 2);
    if (b > mid)
        out += query(a, b, mid + 1, r, m * 2 + 1);
    return out;
}

int main()
{
    scanf("%d", &q);

    R = 1;
    while (R < 1e6)
        R *= 2;

    /// gen
    for (int i = 0; i <= 1000; ++i)
    {
        for (int j = i; j <= 1000; ++j)
        {
            int num = i * i + j * j;
            if (num <= 1000000)
            {
#if DEBUG
                if (num >= 19 && num <= 19)
                    LOG("inserting i: %d j: %d num: %d\n", i, j, num);
#endif
                insert(num);
            }
            else
                break;
        }
    }

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        LOG("for %d %d: \n", a, b);
        int out = query(a, b);
        printf("%d\n", out);
    }
}
