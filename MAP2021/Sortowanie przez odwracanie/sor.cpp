#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> v;
unordered_map<int, int> pos0, pos1;

int n;
int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    LOG("faza 1\n");
#if DEBUG
    for (int i : v)
        LOG("%d ", i);
    LOG("\n");
#endif

    for (int i = 0; i < n; ++i)
        pos0[v[i]] = i;

    LOG("faza 2\n");
    sort(v.begin(), v.end());

    LOG("faza 3\n");
    for (int i = 0; i < n; ++i)
        pos1[v[i]] = i;
#if DEBUG
    LOG("bylo:\n");
    for (const auto& [key, value] : pos0)
        LOG("%d: %d\n", key, value);
    LOG("\njest:\n");
    for (const auto& [key, value] : pos1)
        LOG("%d: %d\n", key, value);
    LOG("\n");
#endif

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        int dist = abs(pos1[v[i]] - pos0[v[i]]);
        LOG("%d bylo na %d a jest na %d, dist: %d\n", v[i], pos0[v[i]], pos1[v[i]], dist);
        if (dist % 2 == 1)
        {
            LOG("%d jest zle\n", v[i]);
            result++;
        }
    }
    result /= 2;
    printf("%d\n", result);
}
