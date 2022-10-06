#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int t[200'000];

ll inline max(ll a, ll b)
{
    return (a > b)? a : b;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);

    ll curr_max = t[0];
    ll max_max = t[0];
    for (int i = 1; i < n; ++i)
    {
        curr_max = max(t[i], t[i] + curr_max);
        max_max = max(max_max, curr_max);
    }
    printf("%lld\n", max_max);
}
    
