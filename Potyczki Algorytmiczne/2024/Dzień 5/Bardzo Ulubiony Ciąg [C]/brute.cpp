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
    vector<int> base(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &base[i]);
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + base[i];
    }
    vector<int> all;
    all.reserve(n * (n + 1) / 2);
    for (int s = 0; s < n; s++) {
        for (int e = s; e < n; e++)
            all.push_back(pre[e + 1] - pre[s]);
    }
    for (int v : all)
        LOG("%d ", v);
    LOG("\n");
    LOG("%ld\n", all.size());


    int result = 0;
    for (int i = 0; i < (int)all.size(); i++) {
        unordered_multiset<int> s;
        for (int j = i + 1; j < (int)all.size(); j++) {
            int missing = -(all[i] + all[j]);
            result += s.count(missing);
            s.insert(all[j]);
        }
    }
    printf("%d\n", result);
}
