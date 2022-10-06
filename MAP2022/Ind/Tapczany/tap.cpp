#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<ll> v;

int main() {
    scanf("%d", &n);
    if (n <= 2) {
        printf("0\n");
        return 0;
    }
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    for (int i : v)
        LOG("%d ", i);
    LOG("\n");
    ll out = 1e9 + 7;
    for (int i = 0; i < n - 1; ++i) {
        ll left = v[i] - v[0];
        ll right = v[n - 1] - v[i + 1];
        ll total = left + right;
        LOG("l: %lld r: %lld t: %lld\n", left, right, total);
        if (total < out)
            out = total;
    }
    printf("%lld\n", out);
}

