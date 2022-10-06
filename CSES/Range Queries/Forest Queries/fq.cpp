#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, q;

vector<vector<char>> raw;

vector<vector<int>> v;

int main()
{
    scanf("%d %d", &n, &q);
    LOG("%d %d\n", n, q);

    v.resize(n + 1);
    v[0].resize(n + 1);
    raw.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        v[i].resize(n + 1);
        raw[i].resize(n + 1);
        for (int j = 1; j <= n; ++j)
        {
            scanf(" %c", &raw[i][j]);
        }
    }

    for (int i = 0; i <= n; ++i)
        v[0][i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        v[i][0] = 0;
        for (int j = 1; j <= n; ++j)
        {
            v[i][j] = v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
            if (raw[i][j] == '*')
                v[i][j]++;
        }
    }
#if DEBUG
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            LOG("%c ", raw[i][j]);
        LOG("\n");
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            LOG("%d ", v[i][j]);
        LOG("\n");
    }
#endif
    for (int i = 0; i < q; ++i)
    {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        int sum = v[y2][x2] - v[y2][x1 - 1] - v[y1 - 1][x2] + v[y1 - 1][x1 - 1];
        printf("%d\n", sum);
    }
}

