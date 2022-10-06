#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char s[(int)1e6 + 2];

int main()
{
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == '9')
        {
            if (s[i + 1] != '1')
            {
                LOG("not 9 to 1 idx: %d, %d %d\n", i, s[i], s[i + 1]);
                printf("NIE\n");
                return 0;
            }
        }
        else
        {
            if (s[i + 1] != s[i] + 1 && s[i + 1] != '1')
            {
                LOG("not n to n + 1, or 9 to 1 idx: %d, %d %d\n", i, s[i], s[i + 1]);
                printf("NIE\n");
                return 0;
            }
        }
    }
    printf("TAK\n");
}

