#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<int> p;
vector<int> k;
vector<int> x;

int main() {
    scanf("%d", &n);
    int mP = INT_MAX;
    int mK = -1;
    p.resize(n);
    k.resize(n);
    x.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &p[i], &k[i], &x[i]);
        mP = min(mP, p[i]);
        mK = max(mK, k[i]);
    }
    vector<int> v(mK - mP + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; p[i] + x[i] * j <= k[i]; j++)
            v[p[i] + x[i] * j - mP]++;
    }
    for (int i = mP; i <= mK; i++)
        LOG("%d: %d\n", i, v[i - mP]);
    for (int i = mP; i <= mK; i++) {
        if (v[i - mP] % 2 == 1) {
            printf("%d %d\n", i, v[i - mP]);
            return 0;
        }
    }
    printf("NIE\n");
}

