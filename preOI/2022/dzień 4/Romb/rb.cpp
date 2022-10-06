#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll a, b;

vector<ll> v;

ll dia(ll n) {
    ll out = n;
    while (n != 0) {
        out *= n % 10;
        n /= 10;
    }
    return out;
}

int main() {
    scanf("%lld%lld", &a, &b);

    v.resize(1'000'000);
    for (int i = 1; i < 1'000'000; i++) {
        //LOG("%d: %lld\n", i, dia(i));
        ll d = dia(i);
        if (d < 1'000'000)
            v[dia(i)]++;
    }

    ll result = 0;
    for (ll i = a; i <= b; i++)
        result += v[i];

    printf("%lld\n", result);
}

