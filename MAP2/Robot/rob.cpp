#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif


int n;

vector<vector<bool>> m;
vector<vector<bool>> cg;

char s[(int)1e3 + 1];

template<typename T>
void rs(vector<vector<T>>& v, int w, int h)
{
    v.resize(h);
    for (int i = 0; i < h; i++)
        v[i].resize(w);
}

vector<vector<bool>> visited;
vector<vector<int>> dist;
void inline bfs(int y, int x)
{
    LOG("bfs start x: %d y: %d\n", x, y);
    queue<pair<int, int>> q;
    LOG("test\n");
    visited[y][x] = true;
    dist[y][x] = 0;
    q.push({y, x});
    LOG("test2\n");

    while (!q.empty())
    {
        pair<int, int> s = q.front(); q.pop();
        int y = s.first;
        int x = s.second;
        LOG("bfs in x:%d y:%d\n", x, y);
        if (!visited[y][x - 1] && cg[y][x - 1]) // left
        {
            visited[y][x - 1] = true;
            dist[y][x - 1] = dist[y][x] + 1;
            q.push({y, x - 1});
        }
        if (!visited[y][x + 1] && cg[y][x + 1]) // right
        {
            visited[y][x + 1] = true;
            dist[y][x + 1] = dist[y][x] + 1;
            q.push({y, x + 1});
        }
        if (!visited[y + 1][x] && cg[y + 1][x]) // up 
        {
            visited[y + 1][x] = true;
            dist[y + 1][x] = dist[y][x] + 1;
            q.push({y + 1, x});
        }
        if (!visited[y - 1][x] && cg[y - 1][x]) // down
        {
            visited[y - 1][x] = true;
            dist[y - 1][x] = dist[y][x] + 1;
            q.push({y - 1, x});
        }
    }

}

int main()
{
    scanf("%d", &n);
    scanf("%s", s);

    int x = 0, y = 0;
    int xm = 0, xl = 0, ym = 0, yl = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'G')
        {
            y++;
            ym = max(ym, y);
        }
        else if (s[i] == 'D')
        {
            y--;
            yl = min(yl, y);
        }
        else if (s[i] == 'P')
        {
            x++;
            xm = max(xm, x);
        }
        else
        {
            x--;
            xl = min(xl, x);
        }
    }
    LOG("xm: %d xl: %d, ym: %d, yl: %d\n", xm, xl, ym, yl);


    int h = -yl + ym + 3;
    int w = -xl + xm + 3;
    LOG("h: %d w: %d\n", h, w);
    rs(m, w, h);
    rs(visited, w, h);
    rs(dist, w, h);
    rs(cg, w, h);
    x = -xl + 1, y = -yl + 1;
    cg[y][x] = true;
    pair<int, int> end;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'G')
            y++;
        else if (s[i] == 'D')
            y--;
        else if (s[i] == 'P')
            x++;
        else
            x--;
        cg[y][x] = true;
        if (i == n - 1)
            end = make_pair(y, x);
    }

    bfs(-yl + 1, -xl + 1);

#if DEBUG
    for (int i = h - 1; i >= 0; --i)
    {
        for (int j = 0; j < w; ++j)
            LOG("%d ", dist[i][j]);
        LOG("\n");
    }
#endif

    if (dist[end.first][end.second] < n)
        printf("NIE\n");
    else
        printf("TAK\n");
}
