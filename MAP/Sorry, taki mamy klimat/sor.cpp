#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> v;
vector<int> h;
vector<int> al;
vector<int> ar;
vector<int> outl;
vector<int> outr;
vector<int> outb;
int n;

int main()
{
    scanf("%d", &n);

    v.resize(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);

    h.resize(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);


    al.resize(n + 2);
    outl.resize(n + 2);
    h[0] = INT_MAX;
    h[n + 1] = INT_MAX;
    LOG("left:\n");
    for (int i = 1; i <= n; ++i)
    {
        int pos = i - 1;
        while (h[pos] < h[i])
        {
            pos = al[pos];
        }
        al[i] = pos;
        int out = i - pos;
        if (pos == 0)
            out = 1000000;
        outl[i] = out;
        LOG("[%d]%d pos: %d out: %d\n", i, h[i], pos, out);
    }
    ar.resize(n + 2);
    outr.resize(n + 2);
    LOG("right:\n");
    for (int i = n; i >= 1; --i)
    {
        int pos = i + 1;
        while (h[pos] < h[i])
        {
            pos = ar[pos];
        }
        ar[i] = pos;
        int out = pos - i;
        if (pos == n + 1)
            out = 1000000;
        outr[i] = out;
        LOG("[%d]%d pos: %d out: %d\n", i, h[i], pos, out);
    }
    outb.resize(n + 2);
    LOG("sum:\n");
    for (int i = 1; i <= n; ++i)
    {
        outb[i] = outl[i] + outr[i] - 1;
        if (outb[i] > 1000000)
            outb[i] = 1000000;
        LOG("[%d]%d out: %d\n", i, h[i], outb[i]);
    }
    sort(v.begin(), v.end());
    sort(outb.begin(), outb.end());
#if DEBUG
    LOG("i:\tv\tout\n");
    for (int i = 0; i < n + 2; ++i)
    {
        LOG("%d:\t%d\t%d\n", i, v[i], outb[i]);
    }
#endif
    int result = 0;
    int vi = 2, outi = 2;
    while (vi < n + 2 && outi < n + 2)
    {
        if (v[vi] <= outb[outi])
        {
            result++;
            vi++;
            outi++;
        }
        else
        {
            outi++;
        }
    }
    printf("%d\n", result);
}

