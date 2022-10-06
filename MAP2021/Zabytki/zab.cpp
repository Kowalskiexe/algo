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
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int most = 1;
    int combo = 1;
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        if (last == v[i])
        {
            combo++;
            most = max(combo, most);
        }
        else
            combo = 1;
        last = v[i];
    }
    LOG("most: %d\n", most);
    printf("%d\n", n - most);
}

