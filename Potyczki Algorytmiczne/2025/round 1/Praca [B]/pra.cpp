#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) cout << __FUNCTION__ << " " << __LINE__ << ": " << __VA_ARGS__ << endl
#else
#define LOG(...)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, t;
    string v;
    cin >> n >> k >> t >> v;
    vector<int> op(n + 1, 0);
    vector<int> req(n + 1, 0);
    vector<int> fre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        req[i + 1] = req[i];
        if (v[i] == '1') {
            // in office
            req[i + 1]++;
        }
        op[i + 1] = op[i];
        if (v[i] == '2') {
            // remote
            op[i + 1]++;
        }
        fre[i + 1] = fre[i];
        if (v[i] == '3') {
            // free
            fre[i + 1]++;
        }
    }
    for (int i = 0; i <= n; i++)
        LOG(i << " " << op[i] << " " << req[i]);

    // case 1: no office
    if (req[n] <= k) {
        LOG("case 1 ");
        int skip = min(req[n] + op[n], k);
        cout << fre[n] + skip << '\n';
        return 0;
    }
    // case 2: office
    int result = -1;
    for (int len = 1; len + 2 * t <= n; len++) {
        for (int start = 1; start + len + 2 * t - 1 <= n; start++) {
            // hhhttoootthhhhh
            //    ^start
            int skippable_left = op[start - 1];
            int skippable_right = op[n] - op[start + t - 1 + len + t];
            int free_left = fre[start - 1];
            int free_right = fre[n] - fre[start + t - 1 + len + t];
            int done = free_left + free_right;
            int skippable = skippable_left + skippable_right;
            int attended_middle = op[start + t - 1 + len] - op[start + t - 1] + req[start + t - 1 + len] - req[start + t - 1];
            int skipped_left = op[start + t - 1] - op[start - 1] + req[start + t - 1];
            int skipped_right = op[start + t - 1 + len + t] - op[start + t - 1 + len] + req[n] - req[start + t - 1 + len];
            int skipped = skipped_left + skipped_right;
            int slack = k - skipped;
            LOG("len=" << len << " start=" << start << " skippable_left=" << skippable_left << " skippable_right=" << skippable_right << " free_left=" << free_left << " free_right=" << free_right << " skipped_left=" << skipped_left << " skipped_right=" << skipped_right);
            if (slack < 0) {
                LOG("impossible");
                continue;
            }
            done += min(slack, skippable);
            LOG("done=" << done);
            result = max(result, done);
        }
    }
    cout << result << '\n';
}
