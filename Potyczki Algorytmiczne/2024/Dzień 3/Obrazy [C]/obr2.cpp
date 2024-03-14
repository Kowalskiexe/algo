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

vector<pair<int, int>> cover(
    pair<int, int> hw,
    const vector<int> &d,
    ll &used
) {
    int h = hw.first;
    int w = hw.second;
    int dx = d.size() - 1;
    while (d[dx] > h || d[dx] > w)
        dx--;
    int left_h = h % d[dx];
    int left_w = w % d[dx];
    ll h_used = h / d[dx];
    ll w_used = w / d[dx];
    ll used_now = h_used * w_used;
    used += used_now;
    LOG("covering %d %d with %d times %lld\n", h, w, d[dx], used_now);
    vector<pair<int, int>> areas_left;
    if (left_w > 0)
        areas_left.emplace_back(d[dx] * h_used, left_w);
    if (left_h > 0)
        areas_left.emplace_back(left_h, d[dx] * w_used);
    if (left_h > 0 && left_w > 0)
        areas_left.emplace_back(left_h, left_w);
    return areas_left;
}

int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    int n;
    scanf("%d", &n);
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    for (int i = 0; i < n; i++)
        LOG("%d ", d[i]);
    LOG("\n");

    if (w % d[0] != 0 || h % d[0] != 0) {
        printf("-1\n");
        return 0;
    }

    ll result = 0;
    queue<pair<int, int>> q;
    q.emplace(h, w);
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        auto areas = cover(c, d, result);
        for (auto a : areas) {
            q.push(a);
        }
    }
    printf("%lld\n", result);
}
