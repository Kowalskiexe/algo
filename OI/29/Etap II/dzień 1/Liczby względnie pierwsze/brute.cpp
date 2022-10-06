// Maciej Kowalski
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

// brute :3

ll n, k;
int c;

int main() {
    scanf("%lld%lld%d", &n, &k, &c);
    
    ll count = 0;
    for (ll i = 1;; i++) {
        if (gcd(n, i) == 1) {
            count++;
            if (count >= k) {
                printf("%lld ", i);
                if (count == k + c - 1) {
                    printf("\n");
                    return 0;
                }
            }
        }
    }
}

