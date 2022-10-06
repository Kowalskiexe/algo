#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1e9 + 7;

ll power(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        ll out = power(a, b / 2);
        return out * out % M;
    } else
        return a * power(a, b - 1) % M;
}

ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = u * u % m;
    if (n % 2 == 1) u = u * x % m;
    return u;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        ll out = modpow(a, b, M);
        out = modpow(out, c, M);
        printf("%lld\n", out);
    }
}

