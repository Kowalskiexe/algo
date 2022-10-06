#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, t;

// n - contestants
// m - submits
// t - time

struct Submit {
    int contes, conjec, score;
    Submit(int a, int b, int c): contes(a), conjec(b), score(c) {}
    bool operator<(const Submit& other) {
        return conjec < other.conjec;
    }
};

vector<Submit> subs;

int main() {
    scanf("%d%d%d", &n, &m, &t);

    subs.reserve(m);
    for (int i = 0; i < m; i++) {
        int contes, conjec, score;
        scanf("%d%d%d", &contes, &conjec, &score);
        subs.emplace_back(contes, conjec, score);
    }
    sort(subs.begin(), subs.end());

    vector<ll> scores(n + 1); // total score
    int j = 0;
    vector<int> top;
    ll top_thres = 0;
    vector<int> winning(n + 1);
    for (int i = 1; i <= t; i++) {
        while (subs[j].conjec == i) {
            scores[subs[j].contes] += subs[j].score;
            if (scores[subs[j].contes] == top_thres)
                top.push_back(subs[j].contes);
            else if (scores[subs[j].contes] > top_thres) {
                top_thres = scores[subs[j].contes];
                top.clear();
                top.push_back(subs[j].contes);
            }
            j++;
        }
        for (int c : top)
            winning[c]++;
        for (int p = 1; p <= n; p++)
            LOG("%lld ", scores[p]);
        LOG(": ");
        for (int p : top)
            LOG("%d ", p);
        LOG("\n");
    }

    int result;
    ll result_thres = 0;
    for (int i = 1; i <= n; i++) {
        if (winning[i] > result_thres) {
            result_thres = winning[i];
            result = i;
        }
    }

    printf("%d\n", result);
}

