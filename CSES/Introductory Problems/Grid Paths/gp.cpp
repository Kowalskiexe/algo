// I guess about 10 times too slow :(

#include <bits/stdc++.h>

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;

char moves[49];

bool visited[7][7];

#if DEBUG
void print_visited()
{
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
            LOG("%d", visited[j][i]);
        LOG("\n");
    }
    LOG("\n");
}
#else
#define print_visited()
#endif

int result;

bool inline is_valid(int x, int y)
{
    if (x > 6 || y > 6 || x < 0 || y < 0 || visited[x][y])
        return false;

    // optimalization 3
    bool x_mid = x > 1 && x < 6;
    if (x_mid && (y == 0 || y == 6))
        return visited[x - 1][y] || visited[x + 1][y];

    bool y_mid = y > 1 && y < 6;
    if (y_mid && (x == 0 || x == 6))
        return visited[x][y - 1] || visited[x][y + 1];

    // optimalization 4
    if (x_mid && y_mid)
    {
        if (visited[x - 1][y] && visited[x + 1][y] && !visited[x][y + 1] && !visited[x][y - 1])
            return false;
        if (!visited[x - 1][y] && !visited[x + 1][y] && visited[x][y + 1] && visited[x][y - 1])
            return false;
    }

    return true;
}

void inline backtrack(int x = 0, int y = 0, int move = 0)
{
    if (!is_valid(x, y))
    {
        LOG("go back from %d %d\n", x, y);
        return;
    }

    if (x == 0 && y == 6)
    {
        if (move == 48)
        {
            result++;
            LOG("hit target %d %d\n", x, y);
        } else if (move < 48) {
            LOG("not whole area covered\n");
        } else if (move > 48)
            LOG("unpredicted behaviour\n");
        // optimalization 2
        return;
    }

    visited[x][y] = true;
    LOG("move %c %d\n", moves[move], move);
    print_visited();
    switch (moves[move])
    {
        case 'U':
            LOG("(%d)fmoving up from %d %d\n", move, x, y);
            backtrack(x, y - 1, move + 1);
            break;
        case 'D':
            LOG("(%d)fmoving down from %d %d\n", move, x, y);
            backtrack(x, y + 1, move + 1);
            break;
        case 'L':
            LOG("(%d)fmoving left from %d %d\n", move, x, y);
            backtrack(x - 1, y, move + 1);
            break;
        case 'R':
            LOG("(%d)fmoving right from %d %d\n", move, x, y);
            backtrack(x + 1, y, move + 1);
            break;
        case '?':
            LOG("(%d)moving up from %d %d\n", move, x, y);
            backtrack(x, y - 1, move + 1); // U

            LOG("(%d)moving down from %d %d\n", move, x, y);
            backtrack(x, y + 1, move + 1); // D

            LOG("(%d)moving left from %d %d\n", move, x, y);
            backtrack(x - 1, y, move + 1); // L

            LOG("(%d)moving right from %d %d\n", move, x, y);
            backtrack(x + 1, y, move + 1); // R
            break;
    }
    visited[x][y] = false;
}

int main()
{
    scanf("%s", moves);
    LOG("%s\n", moves);
#if TRUE
    // otptimalization 1
    grid[0][0] = true;
    if (moves[0] == 'D')
        backtrack(0, 1, 1);
    else // moves[0] == 'R' or not
        backtrack(1, 0, 1);
    result *= 2;
#else
    backtrack();
#endif
    printf("%d\n", result);
}
