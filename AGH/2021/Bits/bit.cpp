#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

/*
1 1 1
5 101 3
25 11001 5
125 1111101 7
625 1001110001 10
3125 110000110101 12
15625 11110100001001 14
78125 10011000100101101 17
390625 1011111010111100001 19
1953125 111011100110101100101 21
9765625 100101010000001011111001 24
48828125 10111010010000111011011101 26
244140625 1110100011010100101001010001 28
1220703125 1001000110000100111001110010101 31
6103515625 101101011110011000100000111101001 33
30517578125 11100011010111111010100100110001101 35
152587890625 10001110000110111100100110111111000001 38
762939453125 1011000110100010101111000010111011000101 40
3814697265625 110111100000101101101011001110100111011001 42
19073486328125 100010101100011100100011000001001000100111101 45
95367431640625 10101101011110001110101111000101101011000110001 47
476837158203125 1101100011010111001001101011011100010111011110101 49
2384185791015625 1000011110000110011110000011001001101110101011001001 52
*/

char s[51];
int n;
ll num;

vector<vector<int>> f;

int road(int idx, int k)
{
    int out = INT_MAX;
    for (int end : f[idx])
    {
        if (end == n - 1)
        {
            LOG("finished: %d\n", k + 1);
            out = min(out, k + 1);
        }
        else
        {
            LOG("from: %d to %d\n", idx, end + 1);
            out = min(out, road(end + 1, k + 1));
        }
    }
    return out;
}

bool inline match(int start, int end, ll target)
{
    if (s[start] == '0')
        return false;
    ll left = num >> (n - end - 1);
    ll ones = (1ll << (end - start + 1)) - 1;
    ll sel = left & ones;
    //LOG("\tmove %d left -> %lld\n", n - end - 1, num >> (n - end - 1));
    //LOG("\tand: %lld\n", (1ll << (end - start + 1)) - 1);
    //LOG("\tsel %d %d: %lld\n", start, end, sel);
    LOG("\tsel: %lld target: %lld, left: %lld ones: %lld\n", sel, target, left, ones);
    return sel == target;
}

int inline bisize(ll n)
{
    int out = 0;
    while (n > 0)
    {
        out++;
        n /= 2;
    }
    return out;
}

int main()
{
    LOG("%lld\n", LLONG_MAX);
    scanf("%s", s);
    if (s[0] == '0')
    {
        printf("-1\n");
        return 0;
    }

    n = strlen(s);
    LOG("n: %d\n", n);
    for (int i = 0; i < n; ++i)
    {
        num <<= 1;
        num += s[i] - '0';
    }
    LOG("num: %lld\n", num);
    match(1, 2, 3);
    
    f.resize(n);
    int l = 1;
    ll d = 1ll;
    while (l <= n)
    {
        LOG("trying: %lld, l: %d\n", d, l);
        for (int i = 0; i <= n - l; ++i)
        {
            int end = i + l - 1;
            if (match(i, end, d))
            {
                LOG("match: %d %d\n", i, end);
                f[i].push_back(end);
            }
            else
                LOG("match: %d %d not\n", i, end);
        }
        d *= 5;
        l = bisize(d);
    }
#if DEBUG
    for (int i = 0; i < n; ++i)
    {
        LOG("%d: ", i);
        for (int j : f[i])
            LOG("%d ", j);
        LOG("\n");
    }
#endif
    int result = road(0, 0);
    if (result != INT_MAX)
        printf("%d\n", result);
    else
        printf("-1\n");
}

