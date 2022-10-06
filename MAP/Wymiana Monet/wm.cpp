#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, M;

int main()
{
    scanf("%lld %lld", &N, &M);
    
    ll base = min(N, M / 2);

    ll rest2 = N - base;
    ll rest1 = M - base * 2;

    ll extra = rest1 / 4;

    printf("%lld\n", base + extra);
}

