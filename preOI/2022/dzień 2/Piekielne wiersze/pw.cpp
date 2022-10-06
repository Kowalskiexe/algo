#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<pair<int, int>> v;

int main() {
    scanf("%d", &n);
    // edge case for n == 1
    
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }

    vector<int> w(n);
    for (int i = 0; i < n; i++)
        w[i] = i;

    vector<int> w_result;
    int result_thresh = -1;
    do {
        int matches = 0;
        for (int i = 0; i < n - 1; i++)
            if (v[w[i]].second == v[w[i + 1]].first)
                matches++;
        if (matches > result_thresh) {
            result_thresh = matches;
            w_result = w;
        }
    } while (next_permutation(w.begin(), w.end()));

#if 0
    for (int i : w_result)
        LOG("%d ", i);
    LOG("\n");
#endif

    vector<pair<int, int>> out(n);
    for (int i = 0; i < n; i++)
        out[i] = v[w_result[i]];

    printf("%d\n", n * 2 - result_thresh);
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (last == out[i].first)
            printf("%d ", out[i].second);
        else
            printf("%d %d ", out[i].first, out[i].second);
        last = out[i].second;
    }
    printf("\n");
}

