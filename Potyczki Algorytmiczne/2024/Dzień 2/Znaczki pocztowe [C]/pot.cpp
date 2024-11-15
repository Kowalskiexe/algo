#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#define DOUT cout
#else
#define LOG(...)
#define DOUT if(0) cout
#endif

int main() {
    int n;
    scanf("%d", &n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        m[in]++;
    }
    for (auto [k, v] : m)
        LOG("%d: %d\n", k, v);
    int last_result = -1;
    for (int d = 1; d <= n; d++) {
        if (last_result == 0) {
            printf("0 ");
        } else {
            int result = 0;
            for (auto &[k, v] : m) {
                result += v / d;
            }
            result *= d;
            printf("%d ", result);
            last_result = result;
        }
    }
    printf("\n");
}
