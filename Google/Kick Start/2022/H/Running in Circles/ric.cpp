#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    for (int ti = 1; ti <= t; ti++) {
        int l, n;
        scanf("%d %d", &l, &n);
        LOG("test %d, l=%d\n", ti, l);
        int pos = 0;
        char last_direc = '-';
        int lapses = 0;
        for (int i = 0; i < n; i++) {
            int d;
            char direc;
            scanf("%d %c ", &d, &direc);
            LOG("run %d in %c, is at %d\n", d, direc, pos);
            if (direc == 'A')
                d *= -1;
            int added = abs(pos + d) / l;
            LOG("\tabs(%d) / %d = %d\n", pos + d, l, abs(pos + d) / l);
            if (last_direc != direc && last_direc != '-')
                added--;
            if (added > 0)
                last_direc = direc;
            // 0 1 2 3
            // FIXME: naprawic odwracanie kierunku
            lapses += added;
            pos = abs(pos + d) % l;
            LOG("added %d, ended at %d\n", added, pos);
            /*
            for (int j = 0; j < d; j++) {
                if (direc == 'C')
                    pos++;
                else
                    pos--;
                if (pos % l == 0) {
                    if (last_direc == direc || last_direc == '-')
                        lapses++;
                    LOG("at starting line, running %c\n", direc);
                    last_direc = direc;
                }
            }
            */
        }
        printf("Case #%d: %d\n", ti, lapses);
    }
}

