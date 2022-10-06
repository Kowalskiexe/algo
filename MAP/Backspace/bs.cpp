#include <bits/stdc++.h>

char t[1000001];

int main()
{
    int l = 0;
    char newread;
    do
    {
        newread = getchar_unlocked();
        t[l] = newread;
        if (t[l] == '<')
            l--;
        else
            l++;
        l = std::max(0, l);
    }
    while (newread != '\n');

    for (int i = 0; i < l; ++i)
        putchar_unlocked(t[i]);
    putchar_unlocked('\n');
}
