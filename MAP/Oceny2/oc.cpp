#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<int> v;

int main()
{
    scanf("%d", &n);
    v.resize(1e5 + 1);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        v[in]++;
    }
#if DEBUG
    for (int i = 1; i <= 100; ++i)
        LOG("%d\n", v[i]);
    LOG("\n");
#endif
    int result = 0;
    for (int i = 1; i <= 1e5 - 2; ++i)
    {
        result = max(result, v[i] + v[i + 2]);
    }
    printf("%d\n", result);
}

