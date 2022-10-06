#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char str[300'001];
int n;

bool inline is_corr(int a, int b, int c)
{
    vector<int> nonzero; nonzero.reserve(3);
    if (a > 0) nonzero.push_back(a);
    if (b > 0) nonzero.push_back(b);
    if (c > 0) nonzero.push_back(c);

    int first = nonzero[0];
    for (int i = 1; i < (int)nonzero.size(); ++i)
        if (nonzero[i] != first)
        {
            LOG("\t%d %d %d wrong\n", a, b, c);
            return false;
        }
    LOG("\t%d %d %d correct\n", a, b, c);
    return true;
}

int main()
{
    scanf("%s", str);
    n = strlen(str);

    int out = 0;
    for (int length = 1; length <= n; ++length)
    {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < length; i++) // init
        {
            switch (str[i])
            {
                case 'a':
                    a++; break;
                case 'b':
                    b++; break;
                case 'c':
                    c++; break;
            }
        }
        if (is_corr(a, b, c))
            out++;

        for (int i = length; i < n; ++i)
        {
            switch (str[i])
            {
                case 'a':
                    a++; break;
                case 'b':
                    b++; break;
                case 'c':
                    c++; break;
            }
            switch (str[i - length])
            {
                case 'a':
                    a--; break;
                case 'b':
                    b--; break;
                case 'c':
                    c--; break;
            }
            if (is_corr(a, b, c))
                out++;
        }
    }
    printf("%d\n", out);
}

