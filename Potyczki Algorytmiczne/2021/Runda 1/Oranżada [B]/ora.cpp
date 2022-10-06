#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    vector<bool> dis(n + 1);
    int dupi = -1;
    for (int i = 0; i < k; ++i)
    {
        if (dis[v[i]])
        {
            dupi = i;
            break;
        }
        dis[v[i]] = true;
    }
    if (dupi == -1)
    {
        printf("0\n");
        return 0;
    }
    int ness = k - dupi;
    LOG("ness: %d\n", ness);
    int has = 0;
    int out = 0;
    for (int i = dupi + 1; i < n; ++i)
    {
        if (!dis[v[i]])
        {
            out += i - dupi - has;
            has++;
            if (has == ness)
                break;
        }
        dis[v[i]] = true;
    }
    if (has == ness)
        printf("%d\n", out);
    else
        printf("-1\n");
}

