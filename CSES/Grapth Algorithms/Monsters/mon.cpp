#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;
vector<vector<char>> v;

pair<int, int> start;
vector<pair<int, int>> mons;

#if DEBUG
void draw_map()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            LOG("%c", v[i][j]);
        LOG("\n");
    }
}
#else
#define draw_map()
#endif

tuple<bool, vector<vector<char>>, pair<int, int>> inline bfs()
{
    int pl_start = 0;
    int pl_end = 0;
    vector<pair<int, int>> players;
    players.push_back(start);
    
    int mons_start = 0;
    int mons_end = mons.size() - 1; // last index
    vector<pair<int, int>> monsters;
    for (auto u : mons)
    {
        LOG("\tadding: %d %d\n", u.Y, u.X);
        monsters.emplace_back(u.Y, u.X);
    }

    vector<vector<char>> route;
    route.resize(n);
    for (int i = 0; i < n; ++i)
        route[i].resize(m);
#if DEBUG
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            route[i][j] = ' ';
#endif
    route[start.Y][start.X] = 'A';

    int pl_added = 1;
    while (pl_added > 0)
    {
        // Monsters
#if DEBUG
        LOG("\tmonster tiles %d (%d %d):\n", mons_end - mons_start + 1, mons_start, mons_end);
        for (int i = mons_start; i <= mons_end ; i++)
            LOG("\t%d %d\n", monsters[i].Y, monsters[i].X);
#endif
        int updated = 0;
        for (int i = mons_start; i <= mons_end; i++) {
            int y = monsters[i].Y;
            int x = monsters[i].X;
            // up
            if (y != 0)
            {
                y--;
                if (v[y][x] == '.' || v[y][x] == 'A')
                {
                    monsters.emplace_back(y, x); updated++;
                    v[y][x] = '#';
                }
                y++;
            }

            // down
            if (y != n - 1)
            {
                y++;
                if (v[y][x] == '.' || v[y][x] == 'A')
                {
                    monsters.emplace_back(y, x); updated++;
                    v[y][x] = '#';
                }
                y--;
            }

            // left
            if (x != 0)
            {
                x--;
                if (v[y][x] == '.' || v[y][x] == 'A')
                {
                    monsters.emplace_back(y, x); updated++;
                    v[y][x] = '#';
                }
                x++;
            }

            // right
            if (x != m - 1)
            {
                x++;
                if (v[y][x] == '.' || v[y][x] == 'A')
                {
                    monsters.emplace_back(y, x); updated++;
                    v[y][x] = '#';
                }
                x--;
            }
        }
        LOG("\tupdated: %d\n", updated);
        mons_start = mons_end + 1;
        mons_end += updated;
        LOG("monsters move\n");
        draw_map();
        LOG("\n");

        // Player
        LOG("\tplayer tiles: %d\n", pl_end - pl_end + 1);
        for (int i = pl_end; i <= pl_end; ++i)
            LOG("\t%d %d\n", players[i].Y, players[i].X);
        updated = 0;
        for (int i = pl_start; i <= pl_end; ++i)
        {
            pair<int, int> a = players[i];
            // up
            if (a.first == 0)
            {
                return make_tuple(true, route, a);
            }
            else
            {
                int y = a.Y - 1, x = a.X;
                if (v[y][x] == '.')
                {
                    players.emplace_back(y, x); updated++;
                    v[y][x] = 'A';
                    route[y][x] = 'U';
                    LOG("\tadding %d %d\n", y, x);
                }
            }

            // down
            if (a.first == n - 1)
            {
                return make_tuple(true, route, a);
            }
            else
            {
                int y = a.Y + 1, x = a.X;
                if (v[y][x] == '.')
                {
                    players.emplace_back(y, x); updated++;
                    v[y][x] = 'A';
                    route[y][x] = 'D';
                    LOG("\tadding %d %d\n", y, x);
                }
            }

            // left
            if (a.second == 0)
            {
                return make_tuple(true, route, a);
            }
            else
            {
                int y = a.Y, x = a.X - 1;
                if (v[y][x] == '.')
                {
                    players.emplace_back(y, x); updated++;
                    v[y][x] = 'A';
                    route[y][x] = 'L';
                    LOG("\tadding %d %d\n", y, x);
                }
            }
            
            // right
            if (a.second == m - 1)
            {
                return make_tuple(true, route, a);
            }
            else
            {
                int y = a.Y, x = a.X + 1;
                if (v[y][x] == '.')
                {
                    players.emplace_back(y, x); updated++;
                    v[y][x] = 'A';
                    route[y][x] = 'R';
                    LOG("\tadding %d %d\n", y, x);
                }
            }
        }
        LOG("\tupdated: %d\n", updated);
        pl_start = pl_end + 1;
        pl_end += updated;
        pl_added = updated;
        LOG("player move\n");
        draw_map();
        LOG("\n");
    }
    return make_tuple(false, vector<vector<char>>(), make_pair(0,0));
}

int main()
{
    scanf("%d %d", &n, &m);

    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        v[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            scanf(" %c", &v[i][j]);
            if (v[i][j] == 'A')
                start = make_pair(i, j);
            if (v[i][j] == 'M')
                mons.emplace_back(i, j);
        }
    }
    LOG("mons size: %ld\n", mons.size());

    draw_map();
    LOG("\n");
    bool success;
    vector<vector<char>> route;
    pair<int, int> s;
    tie(success, route, s) = bfs();
    if (success)
    {
        printf("YES\n");
#if DEBUG
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                LOG("%c", route[i][j]);
            LOG("\n");
        }
#endif
        // back track
        int y = s.Y, x = s.X;
        deque<char> track;
        while (route[y][x] != 'A')
        {
            track.push_front(route[y][x]);
            //printf("%c", route[y][x]);
            switch (route[y][x])
            {
                case 'R':
                    x--;
                    break;
                case 'L':
                    x++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'U':
                    y++;
                    break;
            }
        }
        printf("%ld\n", track.size());
        for (char c : track)
            printf("%c", c);
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }

}

