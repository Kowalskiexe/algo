#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int t[1'000'000];
int n;
int main()
{
    scanf("%d", &n);
    int max_strike = 0;
    set<int> occ;
    int begin = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t[i]);
        LOG("i: %d begin: %d, %d\n", i, begin, t[i]);
        if (occ.count(t[i]) == 1)
        {
            LOG("rep\n");
            if (i - begin > max_strike)
                max_strike = i - begin;
            while (t[begin] != t[i])
            {
                occ.erase(t[begin]);
                begin++;
            }
            occ.erase(t[begin]);
            begin++;
        }
        occ.insert(t[i]);
    }
    if (n - begin > max_strike)
        max_strike = n - begin;
    printf("%d\n", max_strike);
}
