#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char s[(int)1e7 + 1];
char p[(int)1e7 + 1];

int n, m;

bool check(int x, int& score, int& next) {
    score = 0;
    int subs = 0;
    bool lastok = true;
    int subend = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == p[x + i]) {
            if (!lastok && subs == 1)
                subend = x + i - 1;
            score++;
            lastok = true;
        } else {
            if (lastok)
                subs++;
            if (subs == 2) {
                next = subend;
                LOG("\tat %d has 2 subs\n", x);
                return false;
            }
            lastok = false;
        }
    }
    LOG("\tat %d sco: %d, su: %d\n", x, score, subs);
    return true;
}

int main() {
    scanf("%s%s", s, p);
    n = strlen(s);
    m = strlen(p);
    int result = INT_MAX;
    for (int i = 0; i + n - 1 < m; i++) {
        int score = 0, next = -1;
        bool suc = check(i, score, next); 
        if (suc)
            result = min(result, n - score);
        else
            i = next;
    }
    printf("%d\n", result);
}
