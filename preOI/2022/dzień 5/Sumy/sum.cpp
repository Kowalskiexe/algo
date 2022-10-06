#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
int av, ac;
int bv, bc;

bool is_power2(int n) {
    while (n > 1) {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true;
}

int main() {
    scanf("%d", &n);

    int in0;
    scanf("%d", &in0);
    av = in0;
    ac++;
    for (int i = 1; i < n; i++) {
        int in;
        scanf("%d", &in);
        if (in == av)
            ac++;
        else {
            bv = in;
            bc++;
        }
    }

    LOG("av: %d ac: %d\n", av, ac);
    LOG("bv: %d bc: %d\n", bv, bc);

    int result = 0;
    if (is_power2(av + bv)) {
        int pairs = min(ac, bc);
        result += pairs;
        ac -= pairs;
        bc -= pairs;
    }
    if (is_power2(av * 2)) {
        int pairs = ac / 2;
        result += pairs;
        ac -= pairs;
    }
    if (is_power2(bv * 2)) {
        int pairs = bc / 2;
        result += pairs;
        bc -= pairs;
    }
    printf("%d\n", result);
}

