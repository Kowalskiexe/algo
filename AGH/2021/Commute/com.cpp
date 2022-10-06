#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int L, n;

struct Tri
{
    int a, b, c;
    Tri(int a, int b, int c): a(a), b(b), c(c) {}
    bool operator<(const Tri& other) const
    {
        if (this->a != other.a)
            return this->a < other.a;
        else
            return this->b < other.b;
    }
};

vector<Tri> sc;

int power(int b, int p)
{
    if (p == 0) return 1;
    if (p == 1) return b;
    if (p % 2 == 0)
    {
        int out = power(b, p / 2);
        return out * out;
    }
    else
    {
        return b * power(b, p - 1);
    }
}

int main()
{
    scanf("%d %d", &L, &n);
    LOG("L: %d, n: %d\n", L, n);
    LOG("2to3 %d\n", power(2, 3));

    sc.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (b <= L)
            sc.emplace_back(a, b, c);
    }

    sort(sc.begin(), sc.end());

    LOG("sc:\n");
    for (auto i : sc)
        LOG("%d %d %d\n", i.a, i.b, i.c);

    int out = INT_MAX;
    for (int i = 0; i < power(2, sc.size()); ++i)
    {
        LOG("run: %d\n", i);
        int idx = 0;
        int dist = 0;
        for (int j = 0; j < sc.size(); ++j)
        {
            bool add = (i & (1 << j)) >> j;
            LOG("%d: add: %d?\n", j, (int)add);
            if (add)
            {
                LOG("\tnow: %d, to: %d\n", idx, sc[j].a);
                if (idx > sc[j].a)
                {
                    LOG("\tcan't go, aborted\n");
goto skip;
                }
                else
                {
                    dist += (sc[j].a - idx) + sc[j].c;
                    idx = sc[j].b;
                }
            }
        }
        dist += L - idx;
        LOG("dist: %d\n", dist);
        out = min(out, dist);
skip:;
    }
    printf("%d\n", out);
}

