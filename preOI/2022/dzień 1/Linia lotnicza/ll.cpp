#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

// brute :3
// działa do 5

int n;

int main() {
    scanf("%d", &n);

    vector<int> v(n * 2);
    for (int i = 0; i < n * 2; i++)
        v[i] = i;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    do {
        do {
            vector<int> out(n);
            for (int i = 0; i < n; i++)
                out[i] = v[i] + a[i];
            set<int> matches;
            for (int el : out) {
                if (binary_search(next(v.begin(), n), v.end(), el))
                    matches.insert(el);
            }
            if ((int)matches.size() == n) {
                printf("found\n");
                for (int i = 0; i < n; i++)
                    LOG("%d ", v[i]);
                LOG("\n");
                for (int i = 0; i < n; i++)
                    LOG("%d ", a[i]);
                LOG("\n");
                return 0;
            }
        } while (next_permutation(a.begin(), a.end()));
    } while (next_permutation(v.begin(), v.end()));

    printf("NIE\n");
}
