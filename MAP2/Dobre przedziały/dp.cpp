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
vector<int> ar;
vector<int> al;

int f(int i)
{

    LOG("i: %d v: %d l: %d r: %d ", i, v[i], al[i], ar[i]);
    if (v[i] > n)
    {
        LOG("skip\n");
        return 0;
    }
    int rem_left = max(0, v[i] - i);
    int rem_right = max(0, i + v[i] - 1 - n);
    int out = max(0, min(ar[i] - al[i] + 2 - v[i], v[i]));
    LOG("o: %d rl: %d rr: %d -> ", out, rem_left, rem_right);
    LOG("%d\n", out - rem_left - rem_right);
    return out;
}

int main()
{
    scanf("%d", &n);
    LOG("n: %d\n", n);

    v.resize(n + 2);
    ar.resize(n + 2);
    al.resize(n + 2);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);

    for (int i = 1; i <= n; ++i) // left
    {
        int curr = i - 1;
        while (v[curr] >= v[i])
            curr = al[curr];
        al[i] = curr;
    }

    for (int i = n; i >= 1; --i) // right
    {
        int curr = i + 1;
        while (v[curr] >= v[i])
            curr = ar[curr];
        ar[i] = curr;
    }

#if DEBUG
    LOG("v: ");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", v[i]);
    LOG("\ni: ");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", i);
    LOG("\nl: ");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", al[i]);
    LOG("\nr: ");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", ar[i]);
    LOG("\n\n");
#endif

    ll out = 0;
    for (int i = 1; i <= n; ++i)
    {
        int ff = f(i);
        //LOG("%d: %d\n", i, ff);
        out += ff;
    }

    printf("%lld\n", out);
}
