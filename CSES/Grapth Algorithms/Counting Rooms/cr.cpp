#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

#define Y first
#define X second

int n, m;
vector<vector<char>> v;
vector<vector<bool>> b;

void inline dfs(int y, int x)
{
    if (b[y][x]) return;
    b[y][x] = true;
    if (v[y][x - 1] == '.') dfs(y, x - 1);
    if (v[y][x + 1] == '.') dfs(y, x + 1);
    if (v[y - 1][x] == '.') dfs(y - 1, x);
    if (v[y + 1][x] == '.') dfs(y + 1, x);
}

int main()
{
    scanf("%d %d", &n, &m);
    v.resize(n + 2);
    b.resize(n + 2);
    vector<pair<int, int>> dots;
    v[0].resize(m + 2);
    for (int i = 0; i < m + 2; ++i)
        v[0][i] = '#';
    for (int i = 1; i <= n; ++i)
    {
        v[i].resize(m + 2);
        b[i].resize(m + 2);
        v[i][0] = '#';
        v[i][m + 1] = '#';
        for (int j = 1; j <= m; ++j)
        {
            scanf(" %c", &v[i][j]);
            if (v[i][j] == '.')
                dots.emplace_back(i, j);
        }
    }
    v[n + 1].resize(m + 2);
    for (int i = 0; i < m + 2; ++i)
        v[n + 1][i] = '#';

#if DEBUG
    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = 0; j < m + 2; ++j)
            LOG("%c", v[i][j]);
        LOG("\n");
    }
#endif

    int count = 0;
    for (int i = 0; i < dots.size(); ++i)
    {
        if (!b[dots[i].Y][dots[i].X])
        {
            dfs(dots[i].Y, dots[i].X);
            count++;
        }
    }
    printf("%d\n", count);
}
