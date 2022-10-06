#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> d;

int main()
{
    scanf("%d", &n);

    d.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &d[i]);

    ll total = 0;
    for (ll i : d)
        total += i;

    for (int i = 0; i < d; ++i)
    {
        ll res = 0;
        for (int s = 0; s < n; ++s)
        {
            ll sum = 0;
            for (int j = s; j < i; ++j)
                sum += d[j];

            int j = s + 1;
            while (sum <= total - sum)
            {
                sum += d[j];
                res += 2;
            }
        }
        printf("%lld ", res);
    }
}
