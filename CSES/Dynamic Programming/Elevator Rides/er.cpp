// doesn't work
#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

set<int> p;
int n, m;

void inline elevate(int whole, set<int>::iterator end)
{
    int lacks = whole - *end;
    auto it = p.upper_bound(lacks);
    if (it == p.end() || it == p.begin())
        return;
    it--;
    auto newEnd = it;
    p.erase(it);
    p.erase(end);
    elevate(lacks, newEnd);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        p.insert(in);
    }

#if DEBUG
    for (int i : p)
        LOG("%d, ", i);
    LOG("\n");
#endif

    int rides = 0;
    while (!p.empty())
    {
        elevate(m, --p.end());
        rides++;
    }
    printf("%d\n", rides);
}
