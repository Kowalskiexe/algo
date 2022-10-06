#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int l, n;
set<int> lights;
multiset<int> sections;

int main()
{
    scanf("%d %d", &l, &n);
    lights.insert(0);
    lights.insert(l);
    sections.insert(l);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        LOG("IN: %d\n", in);
        
        auto it = upper_bound(lights.begin(), lights.end(), in);
        int b = *it;
        int a = *prev(it);
        int d = b - a;
        int left = in - a;
        int right = b - in;
        LOG("a: %d b: %d\n", a, b);
        sections.erase(sections.find(d));
        sections.insert(left);
        sections.insert(right);
        lights.insert(in);
#if DEBUG
        LOG("lig: ");
        for (int i : lights)
            LOG("%d, ", i);
        LOG("\nsec: ");
        for (int i : sections)
            LOG("%d, ", i);
        LOG("\n");
#endif
        printf("%d ", *prev(sections.end()));
    }

}
