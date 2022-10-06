// Maciej Kowalski
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n;
int a, b;

int main() {
    scanf("%lld%d%d", &n, &a, &b);

    ll pw = 1, e = 0;
    while (pw <= n) {
        pw *= 2;
        e++;
    }

    LOG("e: %lld\n", e);

    if (pw / 2 + pw / 4 > n)
        printf("%lld\n", e * 2 - 2);
    else
        printf("%lld\n", e * 2 - 1);
}

