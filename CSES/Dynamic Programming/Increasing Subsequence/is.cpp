// I was lied to, too slow
#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

int n;
vector<int> v;
vector<int> l;

int main() {
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    l.resize(n);
    for (int k = 0; k < n; ++k) {
        l[k] = 1;
        for (int i = 0; i < k; ++i) {
            if (v[i] < v[k])
                l[k] = max(l[k], l[i] + 1);
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
        result = max(result, l[i]);
    printf("%d\n", result);
}
