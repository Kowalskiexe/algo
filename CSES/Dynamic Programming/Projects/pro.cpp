// doesn't work
#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

struct it3
{
    int start, end, price;
    it3(int start, int end, int price): start(start), end(end), price(price) {}
    bool operator<(const it3& other)
    {
        return this->start < other.start;
    }
};

vector<it3> pro;
vector<int> dp;

int main()
{
    scanf("%d", &n);
    pro.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        scanf("%d %d %d\n", &a, &b, &c);
        pro.emplace_back(a, b, c);
    }

    sort(pro.begin(), pro.end());
    dp.resize(n);
    dp[0] = pro[0].price;
    multiset<int> ends;
    ends.insert(pro[0].end);
    for (int i = 1; i < n; ++i)
    {
#if DEBUG
        for (int j : ends)
            LOG("%d, ", j);
        LOG("\n");
#endif
        auto it = ends.lower_bound(pro[i].start);
        int j = 0;
        if (it == ends.begin())
            j = ends.size();
        else if (it == ends.end())
            j = 0;
        else
        {
            it--;
            j = distance(it, ends.end()) - 1;
        }
        LOG("%d: %d %d %d, j: %d\n", i, pro[i].start, pro[i].end, pro[i].price, j);
        dp[i] = max(pro[i].price + dp[i - j - 1], dp[i - 1]);
        ends.insert(pro[i].end);
    }
#if DEBUG
    for (int i : dp)
        LOG("%d\n", i);
    LOG("\n");
#endif
    printf("%d\n", dp[n - 1]);
}
