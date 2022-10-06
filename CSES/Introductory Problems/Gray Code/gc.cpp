#include <stdio.h>
#include <cstring>

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char str[16];
void inline change(int index)
{
//    LOG("ch: %d\n", index);
    if (index < 0) return;
    if (str[index] == '0')
        str[index] = '1';
    else
        str[index] = '0';
}

int main()
{
    memset(str, '0', 16);

    int n;
    scanf("%d", &n);

    int pow = 1;
    int tmp = n;
    while (tmp)
    {
        pow *= 2;
        tmp--;
    }

    for (int i = 1; i < pow; ++i)
    {
        int offset = 1;
        int mod = 2;
        for (int j = 0; j < n; ++j)
        {
            putchar_unlocked(str[j]);
            if ((i - offset) % mod == 0)
                change(j);
            offset *= 2;
            mod *= 2;
        }
        putchar_unlocked('\n');
    }
    for (int j = 0; j < n - 1; ++j)
        putchar_unlocked('0');
    putchar_unlocked('1');
    putchar_unlocked('\n');
}
