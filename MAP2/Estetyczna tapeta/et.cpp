#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<ll> a;
vector<ll> b;

int main()
{
    scanf("%d", &n);

    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);

    ll result = 0;
    for (int i = 0; i < n; ++i)
    {
        ll in;
        scanf("%lld", &in);
        result += in;
    }

    b.resize(n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == a[i + 1] - 1)
            result += b[a[i]];
    }
    printf("%lld\n", result);
}
