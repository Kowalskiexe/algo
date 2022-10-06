#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

int n;
vector<pair<ll, ll>> b;

int main()
{
    scanf("%d", &n);

    b.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        ll p, r;
        scanf("%lld %lld", &p, &r);
        b.emplace_back(p - r, p + r);
    }

    sort(b.begin(), b.end());

#if DEBUG
    for (auto i : b)
        LOG("%lld %lld\n", i.first, i.second);
#endif

    ll k = 0;
    ll last = b[0].second;
    for (int i = 1; i < n; ++i)
    {
        if (b[i].first < last)
            k++;
        last = b[i].second;
    }
    printf("%lld\n", k);
}
