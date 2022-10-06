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
int start, finish;

vector<vector<int>> adj;
vector<vector<char>> raw;

bool inline raw_valid(int y, int x)
{
    return raw[y][x] == '.' || raw[y][x] == 'A' || raw[y][x] == 'B';
}

int inline toId(int y, int x)
{
    return y * m + x;
}
pair<int, int> inline toYX(int id)
{
    return {id / m, id % m};
}

deque<char> inline bfs()
{
    deque<char> out;
    vector<int> parents(n * m);
    parents[start] = start;
    queue<int> q;
    q.push(start);
    vector<bool> visited(n * m);
    while (!q.empty())
    {
        int a = q.front(); q.pop();
        if (a == finish)
        {
            LOG("finito\n");
            while (a != start)
            {
                pair<int, int> old = toYX(a);
                a = parents[a];
                pair<int, int> now = toYX(a);
                LOG("%d: %d %d -> %d %d ", a, old.Y, old.X, now.Y, now.X);
                if (old.Y == now.Y + 1)
                {
                    LOG("D\n");
                    out.push_front('D');
                }
                if (old.Y == now.Y - 1)
                {
                    LOG("U\n");
                    out.push_front('U');
                }
                if (old.X == now.X + 1)
                {
                    LOG("R\n");
                    out.push_front('R');
                }
                if (old.X == now.X - 1)
                {
                    LOG("L\n");
                    out.push_front('L');
                }
            }
            return out;
        }
        for (int u : adj[a])
        {
            if (visited[u]) continue;
            visited[u] = true;
            parents[u] = a;
            q.push(u);
        }
    }
    return out;
}

int main()
{
    scanf("%d %d", &n, &m);

    raw.resize(n);
    for (int i = 0; i < n; ++i)
    {
        raw[i].resize(m);
        for (int j = 0; j < m; ++j)
            scanf(" %c", &raw[i][j]);
    }

    adj.resize(n * m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (raw[i][j] == 'A')
            {
                start = toId(i, j);
                LOG("start:%d %d|%d %d\n", i, j, toYX(toId(i, j)).first,
                        toYX(toId(i, j)).second);
            }
            if (raw[i][j] == 'B')
            {
                finish = toId(i, j);
                LOG("finish:%d %d|%d %d\n", i, j, toYX(toId(i, j)).first,
                        toYX(toId(i, j)).second);
            }
            if (raw_valid(i, j))
            {
                if (i < n - 1 && raw_valid(i + 1, j))
                {
                    int id1 = toId(i, j);
                    int id2 = toId(i + 1, j);
                    adj[id1].push_back(id2);
                    adj[id2].push_back(id1);
                }
                if (j < m - 1 && raw_valid(i, j + 1))
                {
                    int id1 = toId(i, j);
                    int id2 = toId(i, j + 1);
                    adj[id1].push_back(id2);
                    adj[id2].push_back(id1);
                }
            }
        }
    }
#if DEBUG
    for (auto u : raw)
    {
        for (char v : u)
            LOG("%c", v);
        LOG("\n");
    }
    for (int i = 0; i < m * n; ++i)
    {
        LOG("%d: ", i);
        for (int u : adj[i])
            LOG("%d ", u);
        LOG("\n");
    }
#endif
    deque<char> res = bfs();
    if (res.empty())
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n%ld\n", res.size());
        for (char u : res)
            putchar_unlocked(u);
        putchar_unlocked('\n');
    }
}
