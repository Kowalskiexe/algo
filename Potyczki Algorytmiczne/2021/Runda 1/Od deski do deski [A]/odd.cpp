#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

const ll M = 1e9 + 7;

ll inline power(ll base, ll exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return base % M;
    if (exp % 2 == 0)
    {
        ll out = power(base, exp / 2);
        return out * out % M;
    }
    else
        return base * power(base, exp - 1) % M;
}

ll result = 0;
void inline f(const vector<int>& seq)
{
    ll w = m;
    ll row = 1;
    for (int i : seq)
    {
        row = row * w % M * power(m, i - 2) % M;
        w--;
    }
    LOG("\trow sum: %lld\n", row);
    result = (result + row) % M;
}

void inline gen(vector<int> seq, int sum)
{
    if (sum == n)
    {
        LOG("sum: ");
        for (int i : seq)
            LOG("%d, ", i);
        LOG("\n");
        f(seq);
        return;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (sum + i > n)
            break;
        vector<int> tmp = seq;
        tmp.push_back(i);
        gen(tmp, sum + i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    gen(vector<int>(), 0);
    printf("%lld\n", result);
}
