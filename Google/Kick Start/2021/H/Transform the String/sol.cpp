// 14/14pts
#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int char_dist(char to, char from) {
    int dist1 = abs(from - to);
    int dist2 = 'z' - 'a' + 1 - dist1;
    return min(dist1, dist2);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int ii = 1; ii <= t; ii++) {
        char s[(int)1e5 + 1];
        char f['z' - 'a' + 2];
        scanf(" %s %s", s, f);
        int sn = strlen(s);
        int fn = strlen(f);
        int out = 0;
        for (int i = 0; i < sn; i++) {
            int out2 = INT_MAX;
            for (int j = 0; j < fn; j++) {
                out2 = min(out2, char_dist(f[j], s[i]));
            }
            out += out2;
        }
        printf("Case #%d: %d\n", ii, out);
    }
}
