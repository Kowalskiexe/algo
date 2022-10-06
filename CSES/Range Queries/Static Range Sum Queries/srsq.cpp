#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<ll> pre;

int main()
{
    scanf("%d %d", &n, &q);
    pre.resize(n);
    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        pre[i] = pre[i - 1] + in;
    }

    for (int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0)
            printf("%lld\n", pre[b]);
        else
            printf("%lld\n", pre[b] - pre[a - 1]);
    }
}

