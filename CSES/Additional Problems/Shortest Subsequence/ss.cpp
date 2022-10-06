// doesn't work
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char s[(int)1e6+1];
int main()
{
    scanf("%s", s);
    int n = strlen(s);
    int a = 0, c = 0, g = 0, t = 0;
    for (int i = 0; i < n; ++i)
    {
        switch(s[i])
        {
        case 'A':
            a++; break;
        case 'C':
            c++; break;
        case 'G':
            g++; break;
        case 'T':
            t++; break;
        }
    }

    int mini = INT_MAX; char let;
    if (a < mini)
    {
        mini = a;
        let = 'A';
    }
    if (c < mini)
    {
        mini = c;
        let = 'C';
    }
    if (g < mini)
    {
        mini = g;
        let = 'G';
    }
    if (t < mini)
    {
        mini = t;
        let = 'T';
    }

    for (int i = 0; i < mini + 1; ++i)
        printf("%c", let);
    printf("\n");
}


