#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<ll> fib;

int main()
{
    fib.push_back(1);
    fib.push_back(1);
    int fi = 2;
    while (fib.back() <= 5e18)
    {
        fib.push_back(fib[fi - 1] + fib[fi - 2]);
        fi++;
    }
    for (int i = 0; i < fib.size(); ++i)
        LOG("%d: %lld\n", i, fib[i]);

    ll n = 0;
    scanf("%lld", &n);
    if (n == 1ll)
    {
        printf("1\n");
        return 0;
    }

    vector<pair<ll, int>> divs;
    for (int i = 2; fib[i] <= n; ++i)
    {
        ll tmp = n;
        while (tmp % fib[i] == 0)
        {
            tmp /= fib[i];
            LOG("div: %lld\n", fib[i]);
            divs.emplace_back(fib[i], i);
        }
    }
    LOG("divs:\n");
    for (int i = 0; i < divs.size(); ++i)
        LOG("%lld length:%d\n", divs[i].first, divs[i].second);

    map<ll, int> dp;
    LOG("dp in:\n");
    for (auto i : divs)
        dp[i.first] = i.second;
    for (const auto& [k, v] : dp)
        LOG("%lld: %d\n", k, v);
    for (int i = 0; i < divs.size(); ++i)
    {
        LOG("processing div: %lld, size: %ld\n", divs[i].first, dp.size());
        auto j = dp.end();
        int it = 0;
        while (j != dp.begin())
        {
            --j;
            ll k = j->first;
            LOG("%d: k: %lld\n", it, k);
            it++;
            ll key = k * divs[i].first;
            if (key > n || key <= 0) continue;

            int newv = dp[k] + divs[i].second + 1;
            if (dp[key] == 0)
                dp[key] = newv;
            else
                dp[key] = min(dp[key], newv);
        }
    }
    LOG("dp\n");
    for (const auto& [k, v] : dp)
        LOG("%lld: %d\n", k, v);
    if (dp[n] != 0)
        printf("%d\n", dp[n]);
    else
        printf("NIE\n");
}

