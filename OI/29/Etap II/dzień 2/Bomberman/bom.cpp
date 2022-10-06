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


vector<char> best_path;
void bt(int x, int y, vector<char> path, vector<pair<int, int>> b) {
    if (m[y][x] == 'X')
        return;
    if (!path.empty()) {
        if (path.back() == 'G' || path.back() == 'D')
            if (m[x - 1][y] == 'Q' || m[x + 1][y] == 'Q')
                return;
        if (path.back() == 'L' || path.back() == 'P')
            if (m[x][y - 1] == 'Q' || m[x][y + 1] == 'Q')
                return;
    }
    if (m[y][x] == 'K') {
        LOG("possibility %ld\n", path.size());
        if (path.size() < best_path.size() || best_path.empty())
            best_path = path;
        return;
    }
    if (m[y][x] == '#') {
        if (b.size() == 0)
            b.push_back({y, x});
        else if (b.size() == 1) {
            if (y == b[0].first || x == b[0].second)
                b.push_back({y, x});
            else
                return;
        } else if (b.size() == 2) {
            if (b[0].first == y || b[0].second == x)
                b.push_back({y, x});
            else if (b[1].first == y || b[1].second == x)
                b.push_back({y, x});
            else
                return;
        } else {
            int by = -1, bx = -1;
            sort(b.begin(), b.end());
            for (int i = 0; i < (int)b.size() - 1; i++)
                if (b[i].first == b[i + 1].first)
                    by = b[i].first;
            sort(b.begin(), b.end(), [&](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
            for (int i = 0; i < (int)b.size() - 1; i++)
                if (b[i].second == b[i + 1].second)
                    bx = b[i].second;
            if (by != -1) {
                if (y == by)
                    b.push_back({y, x});
                else
                    return;
            }
            if (bx != -1) {
                if (x == bx)
                    b.push_back({y, x});
                else
                    return;
            }
        }
    }
    int tmp = m[y][x];
    m[y][x] = 'Q';
    // up
    if (m[y - 1][x] != 'Q') {
        path.push_back('G');
        bt(x, y - 1, path, b);
        path.pop_back();
    }
    // down
    if (m[y + 1][x] != 'Q') {
        path.push_back('D');
        bt(x, y + 1, path, b);
        path.pop_back();
    }
    // left
    if (m[y][x - 1] != 'Q') {
        path.push_back('L');
        bt(x - 1, y, path, b);
        path.pop_back();
    }
    // right
    if (m[y][x + 1] != 'Q') {
        path.push_back('P');
        bt(x + 1, y, path, b);
        path.pop_back();
    }
    m[y][x] = tmp;
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

    bt(px, py, vector<char>(), vector<pair<int, int>>());

    printf("%ld\n", best_path.size());
    // TODO: bomb
    for (char c : best_path)
        printf("%c", c);
    printf("\n");
}

