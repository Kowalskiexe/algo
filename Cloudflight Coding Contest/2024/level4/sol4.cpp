#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#define DOUT cout
#else
#define LOG(...)
#define DOUT if(0) cout
#endif

int global_y, global_x;

bool _bt(
    int x,
    int y,
    vector<vector<bool>> &covered,
    vector<char> &path
) {
    if ((int)path.size() == global_x * global_y - 2) {
        DOUT << "found\n";
        for (char ch : path)
            cout << ch;
        cout << endl;
        return true;
    }
    if (covered[y + 1][x] && !covered[y][x - 1] && !covered[y][x + 1])
        return false;
    if (covered[y - 1][x] && !covered[y][x - 1] && !covered[y][x + 1])
        return false;
    if (covered[y][x + 1] && !covered[y + 1][x] && !covered[y - 1][x])
        return false;
    if (covered[y][x - 1] && !covered[y + 1][x] && !covered[y - 1][x])
        return false;
    covered[y][x] = true; 
    bool out = false;
    if (!covered[y - 1][x]) {
        path.push_back('W');
        out |= _bt(x, y - 1, covered, path);
        if (out)
            return true;
        path.pop_back();
    }
    if (!covered[y + 1][x]) {
        path.push_back('S');
        out |= _bt(x, y + 1, covered, path);
        if (out)
            return true;
        path.pop_back();
    }
    if (!covered[y][x - 1]) {
        path.push_back('A');
        out |= _bt(x - 1, y, covered, path);
        if (out)
            return true;
        path.pop_back();
    }
    if (!covered[y][x + 1]) {
        path.push_back('D');
        out |= _bt(x + 1, y, covered, path);
        if (out)
            return true;
        path.pop_back();
    }
    covered[y][x] = false;
    return out;
}

bool bt(int x, int y, int tx, int ty) {
    vector<vector<bool>> covered(
        global_y + 2,
        vector<bool>(global_x + 2, false)
    );
    for (int i = 0; i < global_x + 2; i++) {
        covered[0][i] = true;
        covered[global_y + 1][i] = true;
    }
    for (int i = 0; i < global_y + 2; i++) {
        covered[i][0] = true;
        covered[i][global_x + 1] = true;
    }
    covered[ty + 1][tx + 1] = true;
    vector<char> path;
    path.reserve(100*100);
    return _bt(x + 1, y + 1, covered, path);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        DOUT << "test: " << t + 1 << endl;
        cin >> global_x >> global_y;
        DOUT << "x: " << global_x << " y: " << global_y << endl;
        int tx = -1, ty = -1;
        for (int i = 0; i < global_y; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < global_x; j++) {
                if (line[j] == 'X') {
                    tx = j;
                    ty = i;
                }
            }
        }
        DOUT << "tx: " << tx << " ty: " << ty << endl;
        for (int y = 0; y < global_y; y++) {
            for (int x = 0; x < global_x; x++) {
                if (y == ty && x == tx)
                    continue;
                if (bt(x, y, tx, ty))
                    goto endloop;
            }
        }
    endloop:
        DOUT << endl;
    }
}
