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


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll out = power(a, b);
        printf("%lld\n", out);
    }
}

