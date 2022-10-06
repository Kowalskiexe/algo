#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll biprint(ll n)
{
    printf("%lld ", n);
    vector<int> d;
    while (n > 0)
    {
        d.push_back(n % 2);
        n /= 2;
    }
    for (int i = d.size() - 1; i >= 0; --i)
        printf("%d", d[i]);
    printf(" %ld\n", d.size());
    return d.size();
}

int main()
{
    ll l = biprint(1);
    ll i = 5;
    while (l <= 50)
    {
        l = biprint(i);
        i *= 5;
    }
}

