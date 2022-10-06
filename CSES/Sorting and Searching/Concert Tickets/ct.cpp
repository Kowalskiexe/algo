#include <bits/stdc++.h>

using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int t, c;
multiset<int> tick;
vector<int> cust;

int main()
{
    scanf("%d %d", &t, &c);
    LOG("%d %d\n", t, c);
    
    for (int i = 0; i < t; ++i)
    {
        int in;
        scanf("%d", &in);
        tick.insert(in);
    }

    cust.resize(c);
    for (int i = 0; i < c; ++i)
        scanf("%d", &cust[i]);

    for (int i : cust)
    {
        auto it = tick.upper_bound(i);
        if (it == tick.begin())
        {
            LOG("begin\n");
            printf("-1\n");
        }
        else
        {
            --it;
            LOG("found %d\n", *it);
            printf("%d\n", *it);
            tick.erase(it);
        }
    }
}
