#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<int> a;
vector<int> b;
int main() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    b.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    ll S = 0;
    for (int i = 0; i < n; ++i)
        S += a[i] * b[i];

    ll result = abs(S);
    LOG("S: %lld\n", S);
    for (int i = 0; i < n; ++i) {
        if (S * b[i] < 0) {
            // add
            ll add = abs(S / b[i]);
            ll now = S + add * b[i];
            LOG("%d: a: %d b: %d, add %lld, now %lld\n", i, a[i], b[i], add, now);
            if (abs(now) < result)
                result = abs(now);
            now += b[i];
            LOG("+1? %lld\n", now);
            if (abs(now) < result) {
                LOG("+1\n");
                result = abs(now);
            }
            now -= 2 * b[i];
            LOG("-1? %lld\n", now);
            if (abs(now) < result) {
                LOG("-1\n");
                result = abs(now);
            }
        } else {
            // lower
            ll rem = min(S / b[i], (ll)a[i]);
            ll now = S - rem * b[i];
            LOG("%d: a: %d b: %d, rem %lld, now %lld\n", i, a[i], b[i], rem, now);
            if (abs(now) < result)
                result = abs(now);
            if (rem < (ll)a[i]) {
                now -= b[i];
                LOG("+1? %lld\n", now);
                if (abs(now) < result) {
                    LOG("+1\n");
                    result = abs(now);
                }
                now += 2 * b[i];
                LOG("-1? %lld\n", now);
                if (abs(now) < result) {
                    LOG("-1\n");
                    result = abs(now);
                }
            }
        }
    }
    printf("%lld\n", result);
}

