#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
#define Y first
#define X second

int n, m, sy, sx, ey, ex;

vector<vector<char>> ma;

int result = INT_MAX;
void inline bt(int y, int x, int dist, int hc, bool must_go, pair<int, int> tar)
{

    if (y == ey && x == ex)
    {
        result = min(result, dist);
        return;
    }

    bool nmg = false;
    if (ma[y][x] == '#')
    {
        hc++;
        nmg = true;
    }
    if (hc > 1)
        return;

    LOG("bt: %d %d d: %d, hc: %d, mg %d, ta %d %d, nmg %d\n",
            y, x, dist, hc, (int)must_go, tar.Y, tar.X, (int)nmg);
    int tmp = ma[y][x];
    ma[y][x] = 'c';
    if (!must_go)
    {
        if (y - 1 >= 0 && ma[y - 1][x] != 'c')
            bt(y - 1, x, dist + 1, hc, nmg, {y - 2, x});
        if (y + 1 < n && ma[y + 1][x] != 'c')
            bt(y + 1, x, dist + 1, hc, nmg, {y + 2, x});
        if (x - 1 >= 0 && ma[y][x - 1] != 'c')
            bt(y, x - 1, dist + 1, hc, nmg, {y, x - 2});
        if (x + 1 < m && ma[y][x + 1] != 'c')
            bt(y, x + 1, dist + 1, hc, nmg, {y, x + 2});
    }
    else
    {
        if (tar.Y < 0 || tar.Y < 0 || tar.Y >= n || tar.X >= m)
            return;
        bt(tar.Y, tar.X, dist + 1, hc, false, {0, 0});
    }

    ma[y][x] = tmp;
    LOG("back\n");
}

int main()
{
    scanf("%d %d %d %d %d %d", &n, &m, &sy, &sx, &ey, &ex);
    sy--;
    sx--;
    ey--;
    ex--;

    ma.resize(n);
    for (int i = 0; i < n; ++i)
    {
        ma[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            char in;
            scanf(" %c", &in);
            ma[i][j] = in;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            LOG("%c", ma[i][j]);
        LOG("\n");
    }

    bt(sy, sx, 0, 0, false, {0,0});
    printf("%d\n", result);
}
