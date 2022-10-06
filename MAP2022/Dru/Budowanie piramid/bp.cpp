#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        for (int i : v)
            LOG("%d ", i);
        LOG(" -> ");
        int size = n;
        while (size != 1) {
            vector<int> tmp(size - 2);
            for (int i = 0; i < size - 2; ++i)
                tmp[i] = v[i] ^ v[i + 1] ^ v[i + 2];
            v = tmp;
            size -= 2;
        }
        printf("%d\n", v[0]);
    }
}

