#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

// brute :3

int n;

vector<ll> v;

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);
    
    ll result = 0;
    for (int i = 0; i < n; ++i)
    {
        ll val = n * v[i];
        for (ll j = i - 1, p = n - 1; j >= 0; --j, --p)
            val += p * v[j];
        for (ll j = i + 1, p = n - 1; j < n; ++j, --p)
            val += p * v[j];
        LOG("for %d val: %lld\n", i, val);
        result = max(result, val);
    }
    printf("%lld\n", result);
}
