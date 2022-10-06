#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<int> v;

bool inline update(int from, int to)
{
    if (to > n * 2 || to < 0)
        return false;
    if (v[to] != 0)
    {
        if (v[to] > v[from] + 1)
        {
            v[to] = v[from] + 1;
            return true;
        }
        else
            return false;
    }
    else
    {
        v[to] = v[from] + 1;
        return true;
    }
}

int inline sort_num(int n)
{
    vector<int> d(10);
    while (n > 0)
    {
        d[n % 10]++;
        n /= 10;
    }
    int out = 0;
    for (int i = 9; i >= 0; --i)
    {
        for (int j = 0; j < d[i]; ++j)
        {
            out *= 10;
            out += i;
        }
    }
    return out;
}

int main()
{
    scanf("%d", &n);
    LOG("%d -> %d\n", n, sort_num(n));

    v.resize(n * 2 + 1);

    int changes;
#if DEBUG
    int rounds = 0;
#endif
    do
    {
        changes = 0;
        for (int i = 0; i <= n * 2; ++i)
        {
            if (update(i, i + 1)) changes++;
            if (update(i, i * i)) changes++;
            if (update(i, sort_num(i))) changes++;
        }
#if DEBUG
        rounds++;
        for (int i = 0; i <= n * 2; ++i)
            LOG("%d: %d\n", i, v[i]);
#endif
        for (int i = n * 2; i > 0; --i)
            update(i, i - 1);
    }
    while (changes != 0);

    LOG("rounds: %d\n", rounds);
    printf("%d\n", v[n]);
}
