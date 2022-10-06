#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

int R;
vector<int> minT;
vector<int> maxT;

void inline insert(int idx, int val)
{
    idx +=  R - 1;
    maxT[idx] = val;
    minT[idx] = val;
    do
    {
        idx /= 2;
        maxT[idx] = max(maxT[idx * 2], maxT[idx * 2 + 1]);
        minT[idx] = min(minT[idx * 2], minT[idx * 2 + 1]);
    }
    while (idx != 0);
}

// returns the index of the smallest number in a range between a and b inclusively
int inline query_min(int a, int b, int x)
{
    //LOG("\tmin %d %d, [%d]: %d\n", a, b, x, minT[x]);
    if (a == b)
        return a;

    int mid = (a + b) / 2;
    int lchild = minT[x * 2];
    int rchild = minT[x * 2 + 1];
    if (lchild <= rchild)
        return query_min(a, mid, x * 2);
    else
        return query_min(mid + 1, b, x * 2 + 1);
}

// returns the index of the biggest number in a range between a and b inclusively
int inline query_max(int a, int b, int x)
{
    //LOG("\tmax %d %d, [%d]: %d\n", a, b, x, maxT[x]);
    if (a == b)
        return a;

    int mid = (a + b) / 2;
    int lchild = maxT[x * 2];
    int rchild = maxT[x * 2 + 1];
    if (lchild >= rchild)
        return query_max(a, mid, x * 2);
    else
        return query_max(mid + 1, b, x * 2 + 1);
}

// return value at the supplied index
int inline val(int idx)
{
    return minT[idx + R - 1];
}

int main()
{
    scanf("%d %d", &n, &m);
    R = 1;
    while (R < n)
        R *= 2;
    minT.resize(R * 2);
    for (int& i : minT)
        i = INT_MAX;
    maxT.resize(R * 2);

    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        insert(i, in);
    }

    LOG("min:\n");
    for (int i = 0; i < R * 2; ++i)
        LOG("%d: %d\n", i, minT[i]);
    LOG("max:\n");
    for (int i = 0; i < R * 2; ++i)
        LOG("%d: %d\n", i, maxT[i]);

    LOG("min test: %d\n", query_min(1, R, 1));
    LOG("max test: %d\n", query_max(1, R, 1));

    int max_idx = query_max(1, R, 1);
    int min_idx = query_min(1, R, 1);
    int diff = val(max_idx) - val(min_idx);
    vector<pair<int, int>> moves;
    moves.reserve(m);
    while (diff > 0 && m-- > 0)
    {
        LOG("%d (%d) ->  %d (%d)\n",
                max_idx, val(max_idx), min_idx, val(min_idx));
        insert(max_idx, val(max_idx) - 1);
        insert(min_idx, val(min_idx) + 1);
        moves.emplace_back(max_idx, min_idx);
        LOG("%d (%d), %d (%d)\n",
                max_idx, val(max_idx), min_idx, val(min_idx));
        max_idx = query_max(1, R, 1);
        min_idx = query_min(1, R, 1);
        diff = val(max_idx) - val(min_idx);
        LOG("now min: %d, max: %d, diff: %d\n", min_idx, max_idx, diff);
        LOG("\n");
    }

    printf("%d %ld\n", diff, moves.size());
    for (auto i : moves)
        printf("%d %d\n", i.first, i.second);
}
