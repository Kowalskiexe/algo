#include <stdio.h>
#include <cstring>

int main()
{
    int occur['Z' + 1];
    memset(occur, 0, sizeof(int) * ('Z' + 1));

    char letter = getchar_unlocked();
    while (letter != '\n' && letter)
    {
        occur[letter]++;
        letter = getchar_unlocked();
    }

    char odd = '#';
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        if (occur[i] % 2 == 1)
        {
            if (odd == '#')
            {
                odd = i;
            }
            else
            {
                printf("NO SOLUTION\n");
                return 0;
            }
        }
    }

    // generating the palindrom
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        if (i == odd) continue;
        for (int j = 0; j < occur[i] / 2; ++j)
            putchar_unlocked(i);
    }
    if (odd != '#')
    {
        for (int j = 0; j < occur[odd]; ++j)
            putchar_unlocked(odd);
    }
    for (char i = 'Z'; i >= 'A'; --i)
    {
        if (i == odd) continue;
        for (int j = 0; j < occur[i] / 2; ++j)
            putchar_unlocked(i);
    }
    putchar_unlocked('\n');
}
