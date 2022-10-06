#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n, m;

int main()
{
    scanf("%lld %lld", &n, &m);

    if (m * 2 <= n)
        printf("TAK\n");
    else
        printf("NIE\n");
}

