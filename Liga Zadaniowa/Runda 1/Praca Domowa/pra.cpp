#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll P1 = 29;
const ll P2 = 31;
const ll M = 1'000'000'007;

int n, minimum;
char str[1'000'001];
vector<ll> h1, h2;

vector<ll> pow1, pow2;

ll inline f(char a)
{
    return a - 'a' + 1;
}

pair<ll, ll> inline get_hash(int start, int end)
{
    if (start == 0)
        return make_pair(h1[end], h2[end]);
    else
    {
        ll f = ((h1[end] - h1[start - 1] * pow1[end - start + 1]) % M + M) % M;
        ll s = ((h2[end] - h2[start - 1] * pow2[end - start + 1]) % M + M) % M;
        return make_pair(f, s); 
    }
}

bool inline subword_of(int length, int minimum)
{
    vector<pair<ll, ll>> hashes;
    int size = n - length + 1;
    hashes.reserve(size);
    int max_start = n - length;
    for (int start = 0; start <= max_start; ++start)
    {
        pair<ll, ll> h = get_hash(start, start + length - 1);
        LOG("\tadding: %d %d  %lld-%lld\n", start, start + length - 1, h.first, h.second);
        hashes.push_back(h);
    }

    sort(hashes.begin(), hashes.end());

    int reps = 1;
    pair<ll, ll> last = hashes[0];
    for (int i = 1; i < size; ++i)
    {
        if (hashes[i] == last)
        {
            reps++;
            if (reps >= minimum)
            {
                LOG("\ttrue\n");
                return true;
            }
        }
        else
        {
            reps = 1;
            last = hashes[i];
        }
        LOG("\trep: last: %lld-%lld hash: %lld-%lld r:%d\n",
                last.first, last.second, hashes[i].first, hashes[i].second, reps);
    }
    LOG("\tfalse\n");
    return false; 
}

int main()
{
    scanf("%d %d", &n, &minimum);
    scanf("%s", str);

    LOG("%d %d %s\n", n, minimum, str);

    pow1.reserve(n);
    pow1[0] = 1;
    for (int i = 1; i < n; ++i)
        pow1[i] = pow1[i - 1] * P1 % M;
    pow2.reserve(n);
    pow2[0] = 1;
    for (int i = 1; i < n; ++i)
        pow2[i] = pow2[i - 1] * P2 % M;

    h1.reserve(n);
    h1[0] = f(str[0]);
    for (int i = 1; i < n; ++i)
        h1[i] = (h1[i - 1] * P1 + f(str[i])) % M;
    h2.reserve(n);
    h2[0] = f(str[0]);
    for (int i = 1; i < n; ++i)
        h2[i] = (h2[i - 1] * P2 + f(str[i])) % M;

    int out = -1;
    int p = 1;
    int k = n;
    while (p <= k)
    {
        int d = (p + k) / 2;
        LOG("d: %d\tp:%d k:%d\n", d, p, k);
        if (subword_of(d, minimum))
        {
            out = max(out, d);
            p = d + 1;
        }
        else
            k = d - 1;
    }

    printf("%d\n", out);
}
