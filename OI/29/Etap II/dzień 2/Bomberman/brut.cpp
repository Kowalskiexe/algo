#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<vector<char>> m;

int px, py, kx, ky;

vector<vector<bool>> flipped;
void reset_flip() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (flipped[i][j]) {
                m[i][j] = '#';
                flipped[i][j] = false;
            }
        }
    }
}
void flip(int x, int y) {
    if (m[y][x] == '#') {
        m[y][x] = '.';
        flipped[y][x] = true;
    }
}
void detonate(int bx, int by) {
    int x, y;
    // up
    x = bx, y = by;
    while (m[y][x] != 'X') {
        flip(x, y);
        y--;
    }
    // down
    x = bx, y = by;
    while (m[y][x] != 'X') {
        flip(x, y);
        y++;
    }
    // left
    x = bx, y = by;
    while (m[y][x] != 'X') {
        flip(x, y);
        x--;
    }
    // right
    x = bx, y = by;
    while (m[y][x] != 'X') {
        flip(x, y);
        x++;
    }
}

void DM() {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++)
            LOG("%c", m[i][j]);
        LOG("\n");
    }
}

bool pass(int x, int y) {
    return m[y][x] == '.' || m[y][x] == 'K' || m[y][x] == 'P';
}

vector<vector<int>> bfs(int sx, int sy) {
    vector<vector<int>> dist(n + 2, vector<int>(n + 2, -1));
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2));

    visited[sy][sx] = true;
    dist[sy][sx] = 0;
    q.push({sy, sx});

    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;
        // up
        if (!visited[y - 1][x] && pass(x, y - 1)) {
            q.push({y - 1, x});
            visited[y - 1][x] = true;
            dist[y - 1][x] = dist[y][x] + 1;
        }
        // down
        if (!visited[y + 1][x] && pass(x, y + 1)) {
            q.push({y + 1, x});
            visited[y + 1][x] = true;
            dist[y + 1][x] = dist[y][x] + 1;
        }
        // left
        if (!visited[y][x - 1] && pass(x - 1, y)) {
            q.push({y, x - 1});
            visited[y][x - 1] = true;
            dist[y][x - 1] = dist[y][x] + 1;
        }
        // right
        if (!visited[y][x + 1] && pass(x + 1, y)) {
            q.push({y, x + 1});
            visited[y][x + 1] = true;
            dist[y][x + 1] = dist[y][x] + 1;
        }
    }
    return dist;
}

vector<char> backtrack(const vector<vector<int>>& dist, int kx, int ky, int px, int py) {
    vector<char> path;
    path.reserve(n * 3);
    int x = kx, y = ky;
    while (dist[y][x] != 0) {
        // UP
        if (dist[y - 1][x] == dist[y][x] - 1) {
            path.push_back('D');
            y--;
        }
        // DOWN
        else if (dist[y + 1][x] == dist[y][x] - 1) {
            path.push_back('G');
            y++;
        }
        // LEFT
        else if (dist[y][x - 1] == dist[y][x] - 1) {
            path.push_back('P');
            x--;
        }
        // RIGHT
        else if (dist[y][x + 1] == dist[y][x] - 1) {
            path.push_back('L');
            x++;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    scanf("%d", &n);

    m.resize(n + 2, vector<char>(n + 2, 'X'));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf(" %c", &m[i][j]);

    DM();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (m[i][j] == 'P') {
                py = i;
                px = j;
            } else if (m[i][j] == 'K') {
                ky = i;
                kx = j;
            }
        }
    }

    LOG("px: %d py: %d, kx: %d ky: %d\n", px, py, kx, ky);

    bool subtask1 = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (m[i][j] == '#') {
                subtask1 = false;
                break;
            }
        }
    }

    if (subtask1) {
        LOG("subtask1\n");
        vector<vector<int>> dist = bfs(px, py);
        int result = dist[ky][kx];
        if (result == -1)
            printf("NIE\n");
        else {
            vector<char> path = backtrack(dist, kx, ky, px, py);
            printf("%d\n%d %d\n", result, py, px);
            for (char c : path)
                printf("%c", c);
            printf("\n");
        }
    } else {
        LOG("not st1\n");
        flipped.resize(n + 2, vector<bool>(n + 2));
        int min_dist = INT_MAX;
        vector<vector<int>> d;
        int bx, by;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (m[i][j] == 'X') continue;
                detonate(j, i);
                vector<vector<int>> dist = bfs(px, py);
                if (dist[ky][kx] != -1 && dist[ky][kx] < min_dist) {
                    min_dist = dist[ky][kx];
                    by = i;
                    bx = j;
                    d = dist;
                }
                reset_flip();
            }
        }
        
        if (min_dist == INT_MAX)
            printf("NIE\n");
        else {
            printf("%d\n", min_dist);
            printf("%d %d\n", by, bx);
            vector<char> path = backtrack(d, kx, ky, px, py);
            for (char c : path)
                printf("%c", c);
            printf("\n");
        }
    }
}

