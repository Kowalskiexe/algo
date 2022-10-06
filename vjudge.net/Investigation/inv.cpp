#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const int max_n = 10;
const int max_k = 1'000;

// len, res, sumres
ll dp[max_n + 1][max_k][max_k];

// always positive modulo
int mod(int n, int k) {
    int out = n % k;
    if (out < 0)
        out += k;
    return out;
}

int power10[max_n + 1];

int main() {
    int k;
    scanf("%d", &k);

    power10[0] = 1;
    for (int i = 1; i <= max_n; ++i)
        power10[i] = (power10[i - 1] * (10 % k)) % k;

    for (int d = 0; d < 10; d++)
        dp[1][d % k][d % k]++;
    for (int l = 2; l <= max_n; l++) {
        for (int r = 0; r < k; r++) {
            for (int sr = 0; sr < k; sr++) {
                for (int d = 0; d < 10; d++) {
                    int dr = (d % k) * power10[l - 1] % k; // residual of added digit
                    dp[l][r][sr] += dp[l - 1][mod(r - dr, k)][mod(sr - d, k)];
                }
            }
        }
    }

    // ret result
    printf("1dig: %lld\n", dp[1][0][0]);
    printf("2dig: %lld\n", dp[2][0][0]);

    // ll a, b;
    // scanf("%lld %lld", &a, &b);
    ll x;
    scanf("%lld", &x);
    vector<int> result;
    int residual = 0;
    int sresidual = 0;
    for (int l = max_n; l >= 0; l--) {
        for (int d = 0; d < 10; d++) {
            int dr = (d % k) * power10[l - 1] % k;
            ll occ = dp[l][mod(k - residual - dr, k)][mod(k - sresidual - d, k)];
            LOG("%d:d %d: %lld\n", l,  d, occ);
            if (occ >= x) {
                result.push_back(d);
                residual += dr;
                sresidual += d;
                LOG("yes\n");
                break;
            }
            else
                x -= occ;
        }
    }
    LOG("full: ");
    for (int i : result)
        LOG("%d", i);
    LOG("\n");
    int start = 0;
    while (result[start] == 0)
        start++;
    for (int i = start; i < (int)result.size(); ++i)
        printf("%d", result[i]);
    printf("\n");
}

