#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, k;
vector<int> holes;

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    holes.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &holes[i]);

    vector<int> dist;
    dist.reserve(n);

    for (int i = 1; i < n; ++i)
        dist.push_back(holes[i] - holes[i - 1] - 1);

    sort(dist.begin(), dist.end());
    int out = holes[n - 1] - holes[0] + 1;
#if DEBUG
    LOG("max: %d\n", out);
    for (int i : dist)
        LOG("%d\n", i);
#endif
    k--;
    int removed = 0;
    while (removed < holes.size() && removed < k)
    {
        out -= dist[dist.size() - 1 - removed];
        removed++;
    }
    LOG("RESULT: ");
    printf("%d\n", out);
}
