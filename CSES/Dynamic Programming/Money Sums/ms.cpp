#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll> dp;

int n;

int main()
{
    scanf("%d", &n);

    dp.insert(0);
    for (int i = 0; i < n; ++i)
    {
        ll in;
        scanf("%lld", &in);
        vector<ll> add;
        add.reserve(dp.size());
        for (ll j : dp)
            add.push_back(j + in);
        for (ll j : add)
            dp.insert(j);
    }

    printf("%ld\n", dp.size() - 1);
    for (ll i : dp)
    {
        if (i != 0)
            printf("%lld ", i);
    }
    printf("\n");
}
