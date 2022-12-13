#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int main() {
    int n;
    scanf("%d", &n);
    char tests[n + 1];
    scanf("%s", tests);
    int score = 0;
    int strike = 0;
    int per_test = n / 10;
    for (int i = 0; i < n; i++) {
        if (tests[i] == 'T')
            strike++;
        else
            strike = 0;
        if ((i + 1) % per_test == 0) {
            if (strike == per_test)
                score++;
            strike = 0;
        }
    }
    printf("%d\n", score);
}

