#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<ll> h;

bool f(int x) {
    for (int i = 1; i < n; i++) {
        if ((h[n] + x) * i <= h[i] * n) {
            LOG("\tbad at %d h: %lld\n", i, h[i]);
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    
    h.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        char c;
        scanf(" %c", &c);
        if (c == 'D')
            h[i] = h[i - 1] - 1;
        else
            h[i] = h[i - 1] + 1;
    }

    for (int i = 0; i <= n; i++)
        LOG("%lld ", h[i]);
    LOG("\n");

    int a = 0, b = n * 2 + 1;
    while (a <= b) {
        int mid = (a + b) / 2;
        LOG("trying h: %d\n", mid);
        bool targ = f(mid);
        bool near = f(mid - 1);
        if (targ && (!near || mid == 0)) {
            printf("%d\n", mid);
            return 0;
        }
        if (targ)
            b = mid;
        else
            a = mid + 1;
    }

    LOG("%d: %d\n", 0, f(0));
    LOG("%d: %d\n", 1, f(1));
    LOG("%d: %d\n", 2, f(2));
    LOG("%d: %d\n", 3, f(3));
}

