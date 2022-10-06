#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char a[20];
int k;

void inline shift(int x, int d)
{
    LOG("shift %d -> %d\n", x, d);
    int tmp = a[x];
    for (int i = x; i > d; --i)
        a[i] = a[i - 1];
    a[d] = tmp;
}

int main()
{
    scanf("%s %d", a, &k);
    if (k == 0)
    {
        printf("%s\n", a);
        return 0;
    }
    int l = strlen(a);

    vector<int> d(l);
    for (int i = 1; i < l; ++i)
    {
        int curr = i - 1;
        while (curr >= 0 && a[curr] < a[i])
            curr--;
        int dist = i - curr - 1;
        LOG("for %c : %d %d, dist: %d\n", a[i], curr, i, dist);
        d[i] = dist;
    }

    vector<int> w(l);
    for (int i = 1; i < l; ++i)
    {
        int pos  = l - i;
        //LOG("%d: %d\n", i, pos);
        w[i] = d[i] *  pos;
    }

#if DEBUG
    LOG("%s\n", a);
    for (int i : d)
        LOG("%d ", i);
    LOG("\n");
    for (int i : w)
        LOG("%d ", i);
    LOG("\n");
#endif

    while (k > 0)
    {
        int m = 0, x = 0;
        for (int i = 1; i < l; ++i)
        {
            if (w[i] > m)
            {
                m = w[i];
                x = i;
            }
        }
        int dst = x - min(k, d[x]);
        LOG("move %c at %d to %d\n", a[x], x, dst);
        shift(x, dst);
        w[x] = 0;
        k -= d[x];
    }


    LOG("RESULT: ");
    printf("%s\n", a);
    return 0;
}

