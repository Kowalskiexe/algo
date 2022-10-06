#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

int main() {
    scanf("%d", &n);

    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 0; i < n; ++i)
        r[b[i]]++;

    int k = 0;
    for (int i = 1; i <= n; ++i)
        if (r[i] > 0)
            k++;

    int result = k;
    LOG("init k: %d\n", k);
    for (int i = 0; i < n; ++i) {
        if (l[b[i]] == 0 && r[b[i]] > 1) {
            LOG("making even\n");
            k--;
        }
        if (l[b[i]] > 0 && r[b[i]] == 1) {
            LOG("zeroing\n");
            k++;
        }
        l[b[i]]++;
        r[b[i]]--;
        result = min(result, k);
    }
    printf("%d\n", result);
}

