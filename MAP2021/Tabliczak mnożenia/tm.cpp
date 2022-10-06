#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n, m, q;

vector<ll> v;
int main()
{
    scanf("%lld %lld %lld", &n, &m, &q);

    v.reserve(n * m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            v.push_back(j * i);
    }
    sort(v.begin(), v.end());
    printf("%lld\n", v[q - 1]);
}

