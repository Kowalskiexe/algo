#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n;

pair<ll, ll> f(ll n)
{
    ll even = 0, odd = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                even++;
            else
                odd++;
            if (n / i != i)
            {
                if (n / i % 2 == 0)
                    even++;
                else
                    odd++;
            }
        }
    }
    LOG("%lld -> even: %lld, odd: %lld\n", n, even, odd);
    return make_pair(even, odd);
}

bool is_unbal(ll n)
{
    pair<ll, ll> p = f(n);
    ll& even = p.first;
    ll& odd = p.second;
    return even > odd * 2 || odd > even * 2;
}

vector<ll> unbal;

int main()
{
    scanf("%lld", &n);
    unbal.reserve(1000);
    ll i = 1;
    while (unbal.size() < 1000)
    {
        if (is_unbal(i))
            unbal.push_back(i);
        i++;
    }
    for (int i = 0; i < 1000; ++i)
        LOG("%d: %lld\n", i, unbal[i]);
    printf("%lld\n", unbal[n - 1]);
}
