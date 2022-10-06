#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

int n;
vector<ll> t;

int main()
{
    scanf("%d", &n);
    LOG("n: %d\n", n);

    t.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    sort(t.begin(), t.end());

    ll last = 1;
    if (t[0] != 1)
    {
        printf("1\n");
        return 0;
    }
    ll sum  = 1;
    for (int i = 1; i < n; ++i)
    {
        if (t[i] > sum + 1)
        {
            printf("%lld\n", sum + 1);
            return 0;
        }
        sum += t[i];
    }
    printf("%lld\n", sum + 1); 
}
