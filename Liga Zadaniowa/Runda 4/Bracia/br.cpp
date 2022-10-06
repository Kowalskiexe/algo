#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<pair<int, int>> f;
vector<pair<int, int>> fb;
vector<int> build;
bitset<(int)1e6 + 1> visited;
int main()
{
    scanf("%d", &n);

    f.resize(1e6 + 1);
    build.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        if (!visited[in])
        {
            f[in] = make_pair(i, i);
            visited[in] = true;
            build.push_back(in);
        }
        else
            f[in].second = i;
    }
    fb.reserve(build.size());
    for (int i : build)
        fb.push_back(f[i]);
    sort(fb.begin(), fb.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second; });

    int result = 0;
    int last = -1;
    for (auto i : fb)
    {
        if (i.first > last)
        {
            result++;
            last = i.second;
        }
    }
#if DEBUG
    for (int i = 0; i < 5; ++i)
        LOG("%d: %d %d\n", i, f[i].first, f[i].second);
    LOG("fb:\n");
    for (auto i : fb)
        LOG("%d %d\n", i.first, i.second);
#endif
    printf("%d\n", result);
}

