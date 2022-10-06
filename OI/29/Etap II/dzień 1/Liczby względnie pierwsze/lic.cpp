// Maciej Kowalski
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n, k;
int c;

// except 1
vector<int> get_divs(int n) {
    vector<int> out;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            out.push_back(i);
            if (n / i != i)
                out.push_back(n / i);
        }
    }
    out.push_back(n);
    sort(out.begin(), out.end());
    return out;
}

int main() {
    scanf("%lld%lld%d", &n, &k, &c);

    vector<int> divs = get_divs(n);
    LOG("divs: \n");
    for (int i : divs)
        LOG("%d ", i);
    LOG("\n");

    vector<bool> sieve((int)1e6 + 1);
    for (int i : divs) {
        for (int j = 1; j * i <= (int)1e6; j++)
            sieve[j * i] = true;
    }

    for (int i = 1; i < 20; i++)
        LOG("%d: %d\n", i, (int)sieve[i]);

    int count = 0;
    for (int i = 1; count < k + c - 1; i++) {
        if (!sieve[i]) {
            count++;
            if (count >= k)
                printf("%d ", i);
        }
    }
    printf("\n");
}

