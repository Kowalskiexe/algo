// WA
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

    while (t--) {
        char s[(int)1e5 + 1];
        char f['z' - 'a' + 2];
        scanf(" %s %s", s, f);
        int sn = strlen(s);
        int fn = strlen(f);
        int out = 0;
        LOG("%s\n%s\n", s, f);
        for (int i = 0; i < sn; i++) {
            LOG("matching %c\n", s[i]);
            if (fn == 1)
                out += char_dist(f[0], s[i]);
            else {
                int a = 0, b = fn - 1;
                while (a < b) {
                    int mid = (a + b) / 2;
                    int cd = char_dist(f[mid], s[i]);
                    int cdr = char_dist(f[mid + 1], s[i]);
                    LOG("\t%d %d, %c(%d) %c(%d)\n", a, b, f[mid], cd, f[mid + 1], cdr);
                    if (cd > cdr) {// -> right
                        LOG("\tright\n");
                        a = mid + 1;
                    } else { // <- left
                        LOG("\tleft\n");
                        b = mid;
                    }
                }
                LOG("closesed: %c\n", f[a]);
                out += char_dist(f[a], s[i]);
            }
        }
        printf("%d\n", out);
    }
}
