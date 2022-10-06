#include <stdio.h>
#include <cstring>
#include <cmath>

// is other bigger?
bool inline cmp(char* base, char* other)
{
    // assuming both a same length
    int length = strlen(base);
    for (int i = 0; i < length; ++i)
    {
        if (base[i] < other[i])
            return true;
        if (base[i] > other[i])
            return false;
    }
    // otherwise there're identical
    return false;
}

char* last = new char[9];
void inline print(char* str, char* sel = new char[0], int level = 0)
{
    int count = 0;
    for (int i = 0; str[i] != 0; ++i)
    {
        // @ means a character is removed
        if (str[i] != '@')
        {
            //putchar_unlocked(str[i]);
            sel[level] = str[i];
            level++;
            sel[level] = 0;
            count++;

            char next[9];
            memcpy(next, str, 9);
            next[i] = '@';
            print(next, sel, level);
            level--;
            sel[level] = 0;
        }
    }
    if (count == 0)
    {
        if (last[0] != 0) // checks if not first time
        {
            if (cmp(last, sel))
            {
                printf("%s\n", sel);
                memcpy(last, sel, 9);
            }
        }
        else
        {
            printf("%s\n", sel);
            memcpy(last, sel, 9);
        }
    }
}

long long inline factorial(long long  n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    char str[9];
    scanf("%s", str);
    int length = strlen(str);

    int characters['z' + 1];
    memset(characters, 0, ('z' + 1) * sizeof(int));

    for (int i = 0; str[i] != 0; ++i)
        characters[str[i]]++;

    long long reps = 0;
    for (int i = 'a'; i <= 'z'; ++i)
        if (characters[i] > 1)
            reps += factorial(characters[i]);

    if (reps != 0)
        printf("%lld\n", factorial(length) / reps);
    else
        printf("%lld\n", factorial(length));

    // create base
    char base[9]; // just use str?
    int position = 0;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        for (int j = 0; j < characters[i]; ++j)
        {
            base[position] = i;
            position++;
        }
    }
    base[length] = 0;

    print(base);
}
