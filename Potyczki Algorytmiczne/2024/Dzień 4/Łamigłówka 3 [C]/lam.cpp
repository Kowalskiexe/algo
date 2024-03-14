// 7/10
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

enum Dir {
    row,
    column
};

bool check(const vector<string> &canvas, Dir dir, int nr, char &color) {
    int y = canvas.size();
    int x = canvas[0].size();
    int limit;
    if (dir == Dir::row)
        limit = x;
    else
        limit = y;
    color = '*';
    bool succ = true;
    for (int i = 0; i < limit; i++) {
        int cell;
        if (dir == Dir::row)
            cell = canvas[nr][i];
        else
            cell = canvas[i][nr];

        if (cell != '*') {
            if (color == '*')
                color = cell;
            else {
                if (cell != color) {
                    succ = false;
                    break;
                }
            }
        }
    }
    return succ && color != '*';
}

struct Match {
    char dir, color;
    int nr;
    Match(char dir, char color, int nr): dir(dir), color(color), nr(nr) {}
};

vector<Match> check_axis(vector<string> &canvas, Dir dir) {
    int y = canvas.size();
    int x = canvas[0].size();
    int limit;
    if (dir == Dir::row)
        limit = y; // number of rows
    else
        limit = x; // number of columns

    vector<Match> matches;
    for (int i = 0; i < limit; i++) {
        char color;
        bool found = check(canvas, dir, i, color);
        if (found) {
            if (dir == Dir::row)
                matches.emplace_back('R', color, i + 1);
            else
                matches.emplace_back('K', color, i + 1);

            if (dir == Dir::row) {
                DOUT << "row ";
            } else {
                DOUT << "column ";
            }
            DOUT << i + 1 << " " << color << "\n";

            if (dir == Dir::row) {
                for (int j = 0; j < x; j++)
                    canvas[i][j] = '*';
            } else {
                for (int j = 0; j < y; j++)
                    canvas[j][i] = '*';
            }
        }
    }
    return matches;
}

void test_check();
void test_check_axis();

int main() {
#if DEBUG
    test_check();
    test_check_axis();
#endif
#if !defined(DEBUG)
    ios_base::sync_with_stdio(false);
#endif
    int y, x;
    cin >> y >> x;
    vector<string> canvas(y);
    for (int i = 0; i < y; i++)
        cin >> canvas[i];
    vector<Match> matches;
    bool found_anything;
    do {
        found_anything = false;

        // check all columns
        auto tmp = check_axis(canvas, Dir::column);
        if (tmp.size() > 0)
            found_anything = true;
        matches.insert(
            matches.end(),
            make_move_iterator(tmp.begin()),
            make_move_iterator(tmp.end())
        );
        DOUT << "after checking columns\n";
        for (const Match &m : matches)
            DOUT << m.dir << " " << m.nr << " " << m.color;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++)
                DOUT << canvas[i][j];
            DOUT << "\n";
        }
        // check all rows
        tmp = check_axis(canvas, Dir::row);
        if (tmp.size() > 0)
            found_anything = true;
        matches.insert(
            matches.end(),
            make_move_iterator(tmp.begin()),
            make_move_iterator(tmp.end())
        );
        DOUT << "after checking rows\n";
        for (const Match &m : matches)
            DOUT << m.dir << " " <<  m.nr << " " <<  m.color << "\n";
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++)
                DOUT << canvas[i][j];
            DOUT << "\n";
        }
    } while (found_anything);
    reverse(matches.begin(), matches.end());
    cout << matches.size() << "\n";
    for (const Match &m : matches)
        cout << m.dir << " " << m.nr << " " << m .color << "\n";
}

void test_check() {
    vector<string> canvas = {
        "AAA*",
        "A*B*",
        "****",
        "B*B*"
    };
    // check row 0
    char color;
    bool found = check(canvas, Dir::row, 0, color);
    assert(found);
    assert(color == 'A');

    // check row 1
    found = check(canvas, Dir::row, 1, color);
    assert(!found);

    // check row 2
    found = check(canvas, Dir::row, 2, color);
    assert(!found);

    // check row 3
    found = check(canvas, Dir::row, 3, color);
    assert(found);
    assert(color == 'B');

    // check column 1
    found = check(canvas, Dir::column, 0, color);
    assert(!found);

    // check column 2
    found = check(canvas, Dir::column, 1, color);
    assert(found);
    assert(color == 'A');

    // check column 3
    found = check(canvas, Dir::column, 2, color);
    assert(!found);

    // check column 4
    found = check(canvas, Dir::column, 3, color);
    assert(!found);

    DOUT << "test_check passed\n";
}

void test_check_axis() {
    vector<string> canvas = {
        "AAAA",
        "A*BA",
        "****",
        "AAAA"
    };
    check_axis(canvas, Dir::column);
    // K 1 A
    assert(canvas[0][0] == '*');
    assert(canvas[1][0] == '*');
    assert(canvas[2][0] == '*');
    assert(canvas[3][0] == '*');
    // K 2 A
    assert(canvas[0][1] == '*');
    assert(canvas[1][1] == '*');
    assert(canvas[2][1] == '*');
    assert(canvas[3][1] == '*');
    // K 4 A
    assert(canvas[0][3] == '*');
    assert(canvas[1][3] == '*');
    assert(canvas[2][3] == '*');
    assert(canvas[3][3] == '*');

    check_axis(canvas, Dir::row);
    // R 1 A
    assert(canvas[0][0] == '*');
    assert(canvas[0][1] == '*');
    assert(canvas[0][2] == '*');
    assert(canvas[0][3] == '*');
    // R 2 B
    assert(canvas[1][0] == '*');
    assert(canvas[1][1] == '*');
    assert(canvas[1][2] == '*');
    assert(canvas[1][3] == '*');
    // R 3 A
    assert(canvas[3][0] == '*');
    assert(canvas[3][1] == '*');
    assert(canvas[3][2] == '*');
    assert(canvas[3][3] == '*');

    DOUT << "test_check_axis passed\n";
}
