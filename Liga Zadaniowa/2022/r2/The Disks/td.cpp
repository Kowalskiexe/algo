#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;
vector<int> v;
vector<int> allow;

int main() {
    scanf("%d %d", &n, &m);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    allow.resize(n + 2);
    allow[0] = INT_MAX;
    allow[1] = v[0];
    for (int i = 2; i <= n; ++i)
        allow[i] = min(allow[i - 1], v[i - 1]);

    for (int i = 1; i <= n; ++i)
        LOG("%d ", i);
    LOG("\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", allow[i]);
    LOG("\n");

    int B = n + 1;
    for (int i = 0; i < m; ++i) {
        int size;
        scanf("%d", &size);
        LOG("dropping %d\n", size);
        int a = 0, b = B;
        int stop = -1;
        while (a <= b) {
            int mid = (a + b) / 2;
            LOG("\t%d %d\n", a, b);
            if (allow[mid] < size && allow[mid - 1] >= size) {
                LOG("stopping at %d\n", mid);
                stop = mid;
                break;
            }
            if (allow[mid] >= size)
                a = mid + 1;
            else
                b = mid;
        }
        if (stop == 1) {
            LOG("stuck at the top\n");
            printf("0\n");
            return 0;
        }
        B = stop - 1;
        allow[stop - 1] = 0;
        LOG("new B: %d\n", B);
    }
    printf("%d\n", B);
}

