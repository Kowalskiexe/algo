#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll k;
vector<ll> v;

int main()
{
    scanf("%d %lld", &n, &k);

    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    sort(v.begin(), v.end());

    ll sum = 0;
    ll bestl = 1;
    ll bestm = 1000000;
    for (int i = v.size() - 1; i >= 0; --i)
    {
        sum += v[i];
        // sum / k < v[i]
        if (sum < v[i] * k)
        {
            // sum / k > bestl / bestm
            if (sum * bestm > bestl * k)
            {
                bestl = sum;
                bestm = k;
            }
        }
        else
        {
            // v[i] > bestl / bestm
            if (v[i] * bestm > bestl)
            {
                bestl = v[i];
                bestm = 1;
            }
        }
    }
    ll m = min(bestl, bestm);
    for (ll i = 2; i * i <= m; ++i)
    {
        if (bestl % i == 0 && bestm % i == 0)
        {
            bestl /= i;
            bestm /= i;
        }
    }
    printf("%lld %lld\n", bestl, bestm);
}
