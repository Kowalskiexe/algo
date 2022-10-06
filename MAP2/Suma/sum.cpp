#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

// brute :3


int n;

vector<ll> v;

bool inline brute
(
    ll target_sum,
    int target_size,
    int last_index,
    int except_index,
    int size,
    ll sum
)
{
    if (size == target_size)
        return sum == target_sum;
    for (int i = last_index + 1; i < n; ++i)
    {
        if (i == except_index)
            continue;
        bool out = brute(target_sum, target_size, i, except_index, size + 1, sum + v[i]);
        if (out)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    for (int i = 0; i < n; ++i)
    {
        int can = false;
        for (int s = 1; s <= n; ++s)
        {
            can |= brute(v[i], s, -1, i, 0, 0);
            if (can)
                break;
        }
        printf("%d ", (int)can);
    }
    printf("\n");
}


