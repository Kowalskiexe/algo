#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const ll M = 1e9 + 7;

char s[500'001];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    if (n < 6) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        LOG("%c", s[i]);
    LOG("\n");
    
    vector<bool> brut(n);
    for (int i = n - 6; i < n; i++)
        brut[i] = true;

    int result = 0;
    do {
        vector<int> seq;
        seq.reserve(6);
        for (int i = 0; i < n; i++)
            if (brut[i])
                seq.push_back(s[i]);

        LOG("trying:\n");
        for (int i = 0; i < n; i++)
            LOG("%d", (int)brut[i]);
        LOG("\n");
        for (int i : seq)
            LOG("%c", i);
        LOG("\n");

        char a, b, c, d;
        a = seq[0];
        b = seq[1];
        c = seq[2];
        d = seq[3];
        if (c == seq[4] && d == seq[5] && a != b && a != c && a != d && b != c && b != d && c != d)
            result++;
    } while (next_permutation(brut.begin(), brut.end()));

    printf("%d\n", result);
}

