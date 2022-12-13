#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    int t[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    int f[n], s[n];
    for (int i = 0; i < n; i++)
        f[i] = s[i] = t[i];
    int score_f = 1, score_s = 1;
    for (int i = 1; i < n; i++) {
        // first bigger
        if (i % 2 == 1) {
            if (f[i - 1] > f[i])
                score_f++;
            else
                f[i] = -1'000'000'000;
        } else {
            if (f[i - 1] < f[i])
                score_f++;
            else
                f[i] = 1'000'000'000;
        }

        // second bigger
        if (i % 2 == 1) {
            if (s[i - 1] < s[i])
                score_s++;
            else
                s[i] = 1'000'000'000;
        } else {
            if (s[i - 1] > s[i])
                score_s++;
            else
                s[i] = -1'000'000'000;
        }
    }
    LOG("f: %d d: %d\n", score_f, score_s);
    int out = min(n - score_f, n - score_s);
    printf("%d\n", out);
}
