// 7/10 faster
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

bool check_row(const vector<string> &canvas, int nr, char &color) {
    int x = canvas[0].size();
    color = '*';
    bool succ = true;
    for (int i = 0; i < x; i++) {
        if (canvas[nr][i] != '*') {
            if (color == '*')
                color = canvas[nr][i];
            else {
                if (canvas[nr][i] != color) {
                    succ = false;
                    break;
                }
            }
        }
    }
    return succ && color != '*';
}

bool check_column(const vector<string> &canvas, int nr, char &color) {
    int y = canvas.size();
    color = '*';
    bool succ = true;
    for (int i = 0; i < y; i++) {
        if (canvas[i][nr] != '*') {
            if (color == '*')
                color = canvas[i][nr];
            else {
                if (canvas[i][nr] != color) {
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

void check_all_rows(
    vector<string> &canvas,
    vector<Match> &matches,
    vector<bool> &skip
) {
    int y = canvas.size();
    int x = canvas[0].size();

    for (int i = 0; i < y; i++) {
        // if (skip[i])
        //     continue;
        char color;
        bool found = check_row(canvas, i, color);
        if (found) {
            matches.emplace_back('R', color, i + 1);
            // skip[i] = true;

            DOUT << "row " << i + 1 << " " << color << "\n";

            for (int j = 0; j < x; j++)
                canvas[i][j] = '*';
        }
    }
}

void check_all_columns(
    vector<string> &canvas,
    vector<Match> &matches,
    vector<bool> &skip
) {
    int y = canvas.size();
    int x = canvas[0].size();

    for (int i = 0; i < x; i++) {
        // if (skip[i])
        //     continue;
        char color;
        bool found = check_column(canvas, i, color);
        if (found) {
            matches.emplace_back('K', color, i + 1);
            // skip[i] = true;

            DOUT << "column " << i + 1 << " " << color << "\n";

            for (int j = 0; j < y; j++)
                canvas[j][i] = '*';
        }
    }
}

void test_check_row();
void test_check_column();
void test_check_all_rows();
void test_check_all_columns();

int main() {
#if DEBUG
    test_check_row();
    test_check_column();
    test_check_all_rows();
    test_check_all_columns();
#else
    ios_base::sync_with_stdio(false);
#endif
    int y, x;
    cin >> y >> x;
    vector<string> canvas(y);
    for (int i = 0; i < y; i++)
        cin >> canvas[i];
    vector<Match> matches;
    bool found_anything;
    vector<bool> skip_columns(x, false);
    vector<bool> skip_rows(y, false);
    do {
        found_anything = false;

        int before = matches.size();
        check_all_columns(canvas, matches, skip_columns);
        int after = matches.size();
        if (after > before)
            found_anything = true;
        DOUT << "after checking columns\n";
        for (int i = before; i < after; i++)
            DOUT << matches[i].dir << " " << matches[i].nr << " " << matches[i].color << "\n";
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++)
                DOUT << canvas[i][j];
            DOUT << "\n";
        }

        before = matches.size();
        check_all_rows(canvas, matches, skip_rows);
        after = matches.size();
        if (after > before)
            found_anything = true;
        DOUT << "after checking rows\n";
        for (int i = before; i < after; i++)
            DOUT << matches[i].dir << " " << matches[i].nr << " " << matches[i].color << "\n";
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

void test_check_row() {
    vector<string> canvas = {
        "AAA*",
        "A*B*",
        "****",
        "B*B*"
    };
    // check row 0
    char color;
    bool found = check_row(canvas, 0, color);
    assert(found);
    assert(color == 'A');

    // check row 1
    found = check_row(canvas, 1, color);
    assert(!found);

    // check row 2
    found = check_row(canvas, 2, color);
    assert(!found);

    // check row 3
    found = check_row(canvas, 3, color);
    assert(found);
    assert(color == 'B');

    DOUT << "test_check_row passed\n";
}

void test_check_column() {
    vector<string> canvas = {
        "AAA*",
        "A*B*",
        "****",
        "B*B*"
    };
    bool found;
    char color;

    // check column 1
    found = check_column(canvas, 0, color);
    assert(!found);

    // check column 2
    found = check_column(canvas, 1, color);
    assert(found);
    assert(color == 'A');

    // check column 3
    found = check_column(canvas, 2, color);
    assert(!found);

    // check column 4
    found = check_column(canvas, 3, color);
    assert(!found);

    DOUT << "test_check_column passed\n";
}

void test_check_all_columns() {
    vector<string> canvas = {
        "AAA*",
        "A*B*",
        "****",
        "AAA*"
    };
    vector<Match> matches;
    vector<bool> skip(4, false);
    check_all_columns(canvas, matches, skip);
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

    assert((int)matches.size() == 2);

    DOUT << "test_check_all_columns passed\n";
}

void test_check_all_rows() {
    vector<string> canvas = {
        "A*AA",
        "A*BA",
        "****",
        "AAAA"
    };
    vector<Match> matches;
    vector<bool> skip(4, false);
    check_all_rows(canvas, matches, skip);
    // R 1 A
    assert(canvas[0][0] == '*');
    assert(canvas[0][1] == '*');
    assert(canvas[0][2] == '*');
    assert(canvas[0][3] == '*');
    // R 3 A
    assert(canvas[3][0] == '*');
    assert(canvas[3][1] == '*');
    assert(canvas[3][2] == '*');
    assert(canvas[3][3] == '*');

    assert((int)matches.size() == 2);

    DOUT << "test_check_all_rows passed\n";
}
