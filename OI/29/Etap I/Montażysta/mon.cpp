#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

struct tri
{
    int a, b, c;
    tri(int a, int b, int c): a(a), b(b), c(c) {}
    tri() {}
    bool operator<(const tri& other) const
    {
        return a < other.a;
    }
};
vector<tri> v;

int main()
{
    scanf("%d", &n);

    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int t, d;
        scanf("%d %d", &t, &d);
        v.emplace_back(d, t, i + 1);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
        LOG("%d: ddl:%d t:%d, id:%d\n", i, v[i].a, v[i].b, v[i].c);

    priority_queue<tri> dp;
    int taken = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i].a >= v[i].b + taken) // can add??
        {
            // add
            LOG("%d can add\n", i);
            dp.emplace(v[i].b, v[i].a, v[i].c);
            taken += v[i].b;
        }
        else
        {
            // is replacing better
            if (!dp.empty() && dp.top().a > v[i].b)
            {
                // replace
                LOG("%d repalce top\n", i);
                taken -= dp.top().a;
                taken += v[i].b;
                dp.pop();
                dp.emplace(v[i].b, v[i].a, v[i].c);
            }
            else
            {
                LOG("%d omit\n", i);
            }
        }
        LOG("taken %d, is at %d\n", taken, v[i].a);
    }
    LOG("dp size: %ld\n", dp.size());
    vector<tri> interout;
    interout.reserve(dp.size());
    while (!dp.empty())
    {
        auto t = dp.top(); dp.pop();
        LOG("t:%d d:%d, id:%d\n", t.a, t.b, t.c);
        interout.emplace_back(t.b, t.a, t.c);
    }
    sort(interout.begin(), interout.end());
    LOG("interout:\n");
    for (auto i : interout)
        LOG("t:%d ddl:%d, %d\n", i.a, i.b, i.c);

    printf("%ld\n", interout.size());
    int pos = 1;
    for (int i = 0; i < (int)interout.size(); ++i)
    {
        printf("%d %d\n", interout[i].c, pos);
        pos += interout[i].b;
    }
}

