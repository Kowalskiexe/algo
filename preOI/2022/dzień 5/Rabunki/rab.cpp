#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
set<int> s;
set<int> b;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        s.insert(in);
    }
    unordered_map<int, int> B;
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        b.insert(in);
        B[in] = i + 1;
    }

    ll result = 0;
    vector<int> ord;
    ord.reserve(n);
    while (!s.empty()) {
        int minDist = INT_MAX;
        int minS, minB;
        for (int bank : b) {
            auto it = s.upper_bound(bank);
            int distR;
            if (it == s.end())
                distR = INT_MAX;
            else
                distR = *it - bank;
            int distL = bank - *prev(it);
            int dist, S;
            if (distL <= distR) {
                dist = distL;
                S = *prev(it);
            } else {
                dist = distR;
                S = *it;
            }
            if (dist < minDist) {
                minDist = dist;
                minS = S;
                minB = bank;
            }
        }
        result += minDist;
        LOG("rob bank(%d) at %d\n", B[minB], minB);
        ord.push_back(B[minB]);
        s.erase(minS);
        b.erase(minB);
    }
    printf("%lld\n", result);
    for (int i : ord)
        printf("%d ", i);
    printf("\n");
}

