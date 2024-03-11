#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#define DOUT cout
#else
#define LOG(...)
#define DOUT if(0) cout
#endif

int main() {
    int n;
    scanf("%d", &n);
    vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        counts[in]++;
    }
    LOG("input:\n");
    for (int i = 1; i <= n; i++) {
        LOG("%d: %d\n", i, counts[i]);
    }
    LOG("sorted:\n");
    sort(counts.begin(), counts.end());
    for (int i = 1; i <= n; i++) {
        LOG("%d: %d\n", i, counts[i]);
    }
    int subsets = 0;
    int alloted_all = 0;
    int main_set = n;
    int last_idx = 1;
    while (alloted_all < n) {
        LOG("alloting to %d\n", main_set);
        int alloted = 0;
        int target = counts[main_set] - 1; 
        int idx = last_idx;
        while (alloted < target && idx < main_set) {
            int missing = target - alloted;
            int taken = min(counts[idx], missing);
            counts[idx] -= taken;
            alloted += taken;
            idx++;
        }
        last_idx = idx - 1;
        LOG("alloted %d from main_set and %d from other sets\n",
            counts[main_set], alloted);
        alloted_all += alloted + counts[main_set];
        subsets++;
        main_set--;
    }
    printf("%d\n", subsets);
}
