#include <stdio.h>

int inline get_third(int first, int second)
{
    return 6 - first - second;
}

void inline move(int height, int src, int dest)
{
    if (height == 1)
    {
        putchar_unlocked((char)src + '0');
        putchar_unlocked(' ');
        putchar_unlocked((char)dest + '0');
        putchar_unlocked('\n');
        return;
    }

    int third = get_third(src, dest);

    move(height - 1, src, third);

    putchar_unlocked((char)src + '0');
    putchar_unlocked(' ');
    putchar_unlocked((char)dest + '0');
    putchar_unlocked('\n');

    move(height - 1, third, dest);
}


int main()
{
    int h;
    scanf("%d", &h);
    long long count = 1;
    for (int i = 1; i < h; ++i)
    {
        count *= 2;
        count++;
    }
    printf("%lld\n", count);
    move(h, 1, 3);
}
