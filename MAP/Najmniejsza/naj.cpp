#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char s[20];

int main()
{
    scanf("%s", s);
    int n = strlen(s);

    sort(s, s + n);

    int lz = 0;
    while (s[lz] == '0')
        lz++;

    s[0] = s[lz];
    for (int i = 1; i <= lz; ++i)
        s[i] = '0';

    printf("%s\n", s);
}
