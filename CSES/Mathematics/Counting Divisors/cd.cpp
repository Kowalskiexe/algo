#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

int solve(int x) {
    if (x == 1) return 1;
    int out = 2;
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            if (x / i == i)
                out++;
            else
                out += 2;
        }
    }
    return out;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int in;
        scanf("%d", &in);
        int result = solve(in);
        printf("%d\n", result);
    }
}
        
