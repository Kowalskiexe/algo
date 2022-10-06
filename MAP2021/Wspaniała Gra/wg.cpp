#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char p1[21];
char p2[21];

int main()
{
    scanf(" %s %s", p1, p2);
    int l = strlen(p1);
    LOG("L: %d\n", l);

    int p1p = 0, p2p = 0;
    for (int i = 0; i < l; i+=2)
    {
        if (p1[i] == '[')
        {
            if (p2[i] == '8')
            {
                LOG("papier przegrywa p2++\n");
                p2p++;
            }
            else if (p2[i] != '[')
            {
                LOG("papier wygrywa p1++\n");
                p1p++;
            }
            else
            {
                LOG("remis\n");
            }
        }
        if (p1[i] == '(')
        {
            if (p2[i] == '[')
            {
                LOG("kamień przegrywa p2++\n");
                p2p++;
            }
            else if (p2[i] != '(')
            {
                LOG("kamień wygrywa p1++\n");
                p1p++;
            }
        }
        if (p1[i] == '8')
        {
            if (p2[i] == '(')
            {
                LOG("nożyczki przegrywają p2++\n");
                p2p++;
            }
            else if(p2[i] != '8')
            {
                LOG("nozyczki wygrywaja p1++\n");
                p1p++;
            }
        }
    }
    LOG("1: %d 2: %d\n", p1p, p2p);
    if (p1p > p2p)
        printf("EKIPA 1 WYGRYWA\n");
    else if (p1p == p2p)
        printf("REMIS\n");
    else
        printf("EKIPA 2 WYGRYWA\n");
}


