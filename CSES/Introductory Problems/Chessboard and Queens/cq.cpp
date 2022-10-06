#include <stdio.h>

char board[8][8]; // y by x

bool inline is_valid(int y, int x)
{
    if (board[y][x] == '*')
        return false;

    for (int i = y - 1; i >= 0; --i)
        if (board[i][x] == 'q')
            return false;

    for (int i = y - 1, j = x - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'q')
            return false;

    for (int i = y - 1, j = x + 1; i >= 0 && j < 8; --i, ++j)
        if (board[i][j] == 'q')
            return false;

    return true;
}

int result = 0;
void inline count(int row)
{
    if (row == 8)
    {
        result++;
        return;
    }

    for (int x = 0; x < 8; ++x)
    {
        if (is_valid(row, x))
        {
            board[row][x] = 'q';
            count(row + 1);
            board[row][x] = '.';
        }
    }
}
int main()
{
    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
            board[y][x] = getchar_unlocked();
        getchar_unlocked(); // offst of \n
    }

#if DEBUG
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            putchar_unlocked(board[i][j]);
        putchar_unlocked('\n');
    }
#endif
    count(0);
    printf("%d\n", result);
}

